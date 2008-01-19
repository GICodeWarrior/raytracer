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
	normal.normalize();
}

Plane::~Plane()
{
}

void Plane::setDimensions(Vector n, double d)
{
	normal = n;
	normal.normalize();
	
	distance = d;
}

Intersection Plane::intersect(const Ray &ray) const
{	
	Intersection none;
	double Vd = normal * ray.getVector();
	if (Vd == 0) return none;  // Parallel to plane, no intersection
	
	Point o = ray.getOrigin();
	Vector RO = Vector(o.x, o.y, o.z);
	double VO = -(normal * RO - distance);
	double t = VO/Vd;
	if (t < 0) return none;  // Intersection behind origin
	
	Intersection i(this, ray.getVector() * t + ray.getOrigin());
	return i;
}

Vector Plane::normalAt(const Point &p) const
{
	return normal;
}
