/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

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
