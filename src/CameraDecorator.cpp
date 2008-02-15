#include "CameraDecorator.h"

CameraDecorator::CameraDecorator(Camera *c)
: camera(c)
{
}

CameraDecorator::~CameraDecorator()
{
	delete camera;
}

void CameraDecorator::getImage(int width, int height, Pixel *image) const
{
	camera->getImage(width, height, image);
}
