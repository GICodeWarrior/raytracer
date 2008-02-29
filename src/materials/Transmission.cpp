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

#include "Transmission.h"

#include "../../third-party/vector.h"
#include "../Ray.h"
#include "../World.h"
#include "../Intersection.h"

#include <math.h>

Transmission::Transmission(double t, double d)
: world(NULL), transmissiveness(t), ior(d)
{
}

Transmission::Transmission(PrimitiveModel *s, World *w, double t, double i)
: Material(s), world(w), transmissiveness(t), ior(i)
{
}

Transmission::~Transmission()
{
}

Color Transmission::colorAt(const Ray &r, const Point &p, int depth) const
{
	Vector c = Material::colorAt(r, p, depth).asVector();
	if (depth < 0) return Color(c);
	
	Vector normal = Material::normalAt(p);
	
	double n = 1.0 / ior;

	if (normal * -r.getVector() < 0)
	{
		normal = -normal;
		n = ior;
	}
	
	double tir = n * sin(acos(-r.getVector() * normal));
	
	if (tir > 1)
	{
		Vector reflection = r.getVector() - normal * 2 * (r.getVector() * normal);
		reflection.normalize();
	
		Point origin = p + (reflection * 1e-5);
		Vector reflectColor = world->intersect(Ray(origin, reflection)).getColor(depth).asVector();
	
		c += reflectColor * transmissiveness;
	
		return Color(c);
	}

	double offsetLength = tan(asin(tir));
	
	Vector subNormal = normal * (normal * -r.getVector());
	Vector offset = p + subNormal - (p - r.getVector());
	offset.normalize();
	offset *= offsetLength;
	
	Vector transmission = p - normal + offset - p;
	transmission.normalize();
	
	Point origin = p + (transmission * 1e-5);
	Vector transmitColor = world->intersect(Ray(origin, transmission)).getColor(depth).asVector();
	
	c += transmitColor * transmissiveness;
	
	return Color(c);
}
