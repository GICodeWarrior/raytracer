/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

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

Intersection Sphere::intersect(const Ray& ray) const
{	
	Vector deltap = ray.getOrigin() - origin;
	double a = ray.getVector() * ray.getVector();
	double b = 2 * deltap * ray.getVector();
	double c = deltap * deltap - radius * radius;
	
	double disc = b * b - 4 * a * c;
	if (disc < 0) return Intersection();  // No intersection
	disc = sqrt(disc);
	
	double q;
	if (b < 0)
        q = (-b - disc) * 0.5;
    else
        q = (-b + disc) * 0.5;
	
	double r1 = q / a;
	double r2 = c / q;
	
	if (r1 > r2)
	{
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	
	double distance = r1;
	if (distance < 0) distance = r2;
	if (distance < 0) return Intersection();  // No intersection
	
	return Intersection(this, ray, ray.getVector() * distance + ray.getOrigin());
}

Vector Sphere::normalAt(const Point &p) const
{
	Vector normal = p - origin;
	normal.normalize();
	return normal;
}
