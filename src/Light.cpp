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

#include "Light.h"

#include "World.h"
#include "Ray.h"
#include "Intersection.h"

Light::Light(Point p, Color c, World *w)
: origin(p), tint(c), world(w)
{
}

Light::~Light()
{
}

bool Light::intersects(const Point &p) const
{
	Intersection i = world->intersect(Ray(origin, p - origin));
	const PrimitiveModel *model = i.getModel();
	if ((model) && (model->normalAt(p) * (origin - p) < 0))
	{
		return false;
	}
	return i.getPoint().near(p);
}

const Point& Light::getOrigin() const
{
	return origin;
}

const Color& Light::getTint() const
{
	return tint;
}
