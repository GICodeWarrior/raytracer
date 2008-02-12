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
	double Vd = normal * ray.getVector();
	if (Vd == 0) return Intersection();  // Parallel to plane, no intersection
	
	double VO = distance - normal *
				Vector(ray.getOrigin().x, ray.getOrigin().y, ray.getOrigin().z);
	double t = VO/Vd;
	if (t < 0) return Intersection();  // Intersection behind origin
	
	return Intersection (this, ray, ray.getVector() * t + ray.getOrigin());
}

Vector Plane::normalAt(const Point &p) const
{
	return normal;
}
