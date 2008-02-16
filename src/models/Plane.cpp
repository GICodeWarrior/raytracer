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

void Plane::setDimensions(Vector &n, double d)
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
	
	return Intersection(this, ray, ray.getVector() * t + ray.getOrigin());
}

Vector Plane::normalAt(const Point &p) const
{
	return normal;
}
