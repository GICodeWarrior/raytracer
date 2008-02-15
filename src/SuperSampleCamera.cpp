#include "SuperSampleCamera.h"

#include "../third-party/vector.h"
#include "Color.h"

SuperSampleCamera::SuperSampleCamera(Camera *c, unsigned int samples)
: CameraDecorator(c), samples(samples)
{
}

SuperSampleCamera::~SuperSampleCamera()
{
}

void SuperSampleCamera::getImage(int width, int height, Pixel *image) const
{
	int superWidth = width * samples;
	int superHeight = height * samples;
	
	Pixel *superImage = new Pixel[superWidth * superHeight];
	
	CameraDecorator::getImage(superWidth, superHeight, superImage);
	
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Vector color = Color(0,0,0).asVector();
			
			for (unsigned int superY = 0; superY < samples; ++superY)
			{
				for (unsigned int superX = 0; superX < samples; ++superX)
				{
					int newY = y * samples + superY;
					int newX = x * samples + superX;
					int index = newY * superWidth + newX;
					color += Color(superImage[index]).asVector();
				}
			}
			
			color /= int(samples * samples);
			image[y * width + x] = Color(color).asPixel();
		}
	}
	
	delete[] superImage;
}
