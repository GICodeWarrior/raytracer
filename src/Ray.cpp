#include "Ray.h"
#include "Intersection.h"

Ray::Ray(Point p, Vector v)
: point(p), vector(v)
{
}

Ray::~Ray()
{
}

Point Ray::getOrigin() const
{
	return point;
}

Vector Ray::getVector() const
{
	return vector;
}
