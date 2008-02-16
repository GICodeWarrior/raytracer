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

#include "Reflection.h"

#include "../../third-party/vector.h"
#include "../Ray.h"
#include "../World.h"
#include "../Intersection.h"

Reflection::Reflection(PrimitiveModel *s, World *w, double r)
: Material(s), world(w), reflectivity(r)
{
}

Reflection::~Reflection()
{
}

Color Reflection::colorAt(const Ray &r, const Point &p, int depth) const
{
	Vector color = Material::colorAt(r, p, depth).asVector();
	if (depth < 0) return Color(color);
	
	Vector normal = Material::normalAt(p);
	
	Vector reflection = r.getVector() - 2 * normal * (r.getVector() * normal);
	reflection.normalize();
	
	Point origin = p + (reflection * 1e-5);
	Vector reflectColor = world->intersect(Ray(origin, reflection)).getColor(depth).asVector();
	
	color += reflectColor * reflectivity;
	
	return Color(color);
}
