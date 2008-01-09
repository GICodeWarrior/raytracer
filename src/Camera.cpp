#include "Camera.h"

#include "../third-party/point.h"
#include "../third-party/vector.h"

#include "Intersection.h"
#include "Color.h"
#include "Ray.h"

Camera::Camera(Model *s)
: scene(s)
{
}

Camera::~Camera()
{
}

Pixel* Camera::getImage()
{
	int imageWidth = 640;
	int imageHeight = 480;
	
	Pixel* image = new Pixel[imageWidth * imageHeight];
	
	double viewWidth = 1.33;
	double viewHeight = 1.0;
	
	double viewDistance = 1.0;
	
	Point cameraOrigin(0.0, 3.0, -6.0);
	
	Point viewOrigin(viewWidth / 2, viewHeight / 2);
	Vector viewOffset(0.0, 0.0);
	
	Point viewIntersection;
	Vector castDirection;
	
	for (int y = 0; y < imageHeight; ++y)
	{
		viewOffset.y = viewHeight / imageHeight * y;
		
		for (int x = 0; x < imageWidth; ++x)
		{
			viewOffset.x = viewWidth / imageWidth * x;
			viewIntersection = viewOrigin + viewOffset;
			castDirection.x = viewIntersection.x;
			castDirection.y = viewIntersection.y;
			castDirection.z = viewDistance;
			
			Ray casting(cameraOrigin, castDirection);
			Intersection i = scene->intersect(casting);
			image[y * imageWidth + x] = i.getColor().asPixel();
		}
	}
	
	return image;
}
