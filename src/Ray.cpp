#include "Ray.h"
#include "Intersection.h"

Ray::Ray(Point p, Vector v)
: point(p), vector(v)
{
}

Ray::~Ray()
{
}

const Point& Ray::getOrigin() const
{
	return point;
}

const Vector& Ray::getVector() const
{
	return vector;
}
