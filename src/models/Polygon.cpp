#include "Polygon.h"

#include "../Intersection.h"
#include "../Ray.h"

Polygon::Polygon(vector<Point> v, Color c)
: PrimitiveModel(c), verticies(v)
{
}

Polygon::~Polygon()
{
}

Intersection Polygon::intersect(Ray &ray)
{
	Intersection none;
	return none;
}
