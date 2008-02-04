#include "Camera.h"

#include "../third-party/point.h"
#include "../third-party/vector.h"

#include "Intersection.h"
#include "Color.h"
#include "Ray.h"

Camera::Camera(const World *s, Point o, Vector lookAt)
: scene(s), origin(o)
{
	double width = 1.33;
	double height = 1.0;
	double distance = 1.0;
	
	lookAt.normalize();
	lookAt *= distance;
	direction = lookAt;
	
	right = Vector(0.0, 1.0, 0.0) ^ lookAt;
	right.normalize();
	right *= width;
	
	up = right ^ lookAt;
	up.normalize();
	up *= height;
}

Camera::~Camera()
{
}

Pixel* Camera::getImage(int imageWidth, int imageHeight, Pixel *image) const
{	
	double viewWidth = 1.33;
	double viewHeight = 1.0;
	
	double viewDistance = 1.0;
	
	//Point viewOrigin = origin + direction - (right / 2) + (up / 2);
	Point viewOrigin(-viewWidth / 2, viewHeight / 2);
	Vector viewOffset(0.0, 0.0, 0.0);
	
	Point viewIntersection;
	Vector castDirection;
	
	for (int y = 0; y < imageHeight; ++y)
	{
		viewOffset.y = -viewHeight / imageHeight * y;
		
		for (int x = 0; x < imageWidth; ++x)
		{
			viewOffset.x = viewWidth / imageWidth * x;
			viewIntersection = viewOrigin + viewOffset;
			castDirection.x = viewIntersection.x;
			castDirection.y = viewIntersection.y;
			castDirection.z = viewDistance;
			
			Ray casting(origin, castDirection);
			Intersection i = scene->intersect(casting);
			image[y * imageWidth + x] = i.getColor().asPixel();
		}
	}
	
	return image;
}
