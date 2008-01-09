#include "Ray.h"
#include "Intersection.h"

Ray::Ray(Point p, Vector v)
: point(p), vector(v)
{
}

Ray::~Ray()
{
}

Point Ray::getOrigin()
{
	return point;
}

Vector Ray::getVector()
{
	return vector;
}
