#include "Plane.h"

#include "../Intersection.h"
#include "../Ray.h"

Plane::Plane(Color c)
: PrimitiveModel(c)
{
}

Plane::Plane(Vector n, double d, Color c)
: PrimitiveModel(c), normal(n), distance(d)
{
}

Plane::~Plane()
{
}

void Plane::setDimensions(Vector n, double d)
{
	normal = n;
	distance = d;
}

Intersection Plane::intersect(Ray &ray)
{	
	Intersection none;
	double Vd = normal * ray.getVector();
	if (Vd == 0) return none;  // Parallel to plane, no intersection
	
	Point o = ray.getOrigin();
	Vector RO = Vector(o.x, o.y, o.z);
	double VO = -(normal * RO + distance);
	double distance = VO/Vd;
	if (distance < 0) return none;  // Intersection behind origin
	
	Intersection i(this, ray.getVector() * distance + ray.getOrigin());
	return i;
}

Vector Plane::getNormal()
{
	return normal;
}
