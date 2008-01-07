#include "Ray.h"
#include "Intersection.h"

#include "../third-party/vector.h"

Ray::Ray(Point p, Vector v)
: point(p)
{
}

Ray::~Ray()
{
}

Point Ray::getPoint()
{
	return point;
}
