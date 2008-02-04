#include "Camera.h"

#include "../third-party/point.h"
#include "../third-party/vector.h"

#include "Intersection.h"
#include "Color.h"
#include "Ray.h"

Camera::Camera(const World *s, Point o, Point lookAt)
: scene(s), origin(o)
{
	double width = 1.33;
	double height = 1.0;
	double distance = 1.0;
	
	direction = lookAt - origin;
	direction.normalize();
	direction *= distance;
	
	right = Vector(0.0, 1.0, 0.0) ^ direction;
	right.normalize();
	right *= width;
	
	up = right ^ direction;
	up.normalize();
	up *= -height;
}

Camera::~Camera()
{
}

void Camera::getImage(int imageWidth, int imageHeight, Pixel *image) const
{	
	Point viewOrigin(origin + direction - (right / 2) + (up / 2));
	
	for (int y = 0; y < imageHeight; ++y)
	{
		Vector verticalOffset(up * (y / (double)imageHeight));
		
		for (int x = 0; x < imageWidth; ++x)
		{
			Vector horizontalOffset(right * (x / (double)imageWidth));
			Point intersection(viewOrigin + horizontalOffset - verticalOffset);
			
			Vector castDirection(intersection - origin);
			castDirection.normalize();
			
			Intersection i = scene->intersect(Ray(origin, castDirection));
			image[y * imageWidth + x] = i.getColor().asPixel();
		}
	}
}
