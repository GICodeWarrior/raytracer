#include "Sphere.h"
#include "../Intersection.h"
#include "../Ray.h"

#include <math.h>

Sphere::Sphere(Point o, double r, Color c)
: PrimitiveModel(c), origin(o), radius(r)
{
}

Sphere::~Sphere()
{
}

Intersection Sphere::intersect(Ray& ray)
{
	Intersection none;
	Vector deltap;
	double a, b, c;
	double disc, q;
	double r1, r2;
	double distance;
	
	deltap = ray.getPoint() - origin;
	a = ray.getVector() * ray.getVector();
	b = 2 * deltap * ray.getVector();
	c = deltap * deltap - radius * radius;
	
	disc = b * b - 4 * a * c;
	if (disc < 0) return none;  // No intersection
	disc = sqrt(disc);
	
	if (b < 0)
        q = (-b - disc) / 2.0;
    else
        q = (-b + disc) / 2.0;
	
	r1 = q / a;
	r2 = c / q;
	
	if (r1 > r2)
	{
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	
	distance = r1;
	if (distance < 0) distance = r2;
	if (distance < 0) return none;  // No intersection
	
	Intersection i(this, ray.getVector() * distance + ray.getPoint());
	return i;
}
