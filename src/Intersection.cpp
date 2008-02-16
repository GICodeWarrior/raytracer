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

#include "Intersection.h"
#include "Ray.h"

#include "models/PrimitiveModel.h"

Intersection::Intersection()
: model(NULL), ray(Point(), Vector())
{
}

Intersection::Intersection(const PrimitiveModel *m, Ray r, Point p)
: model(m), ray(r), point(p)
{
}

Intersection::~Intersection()
{
}

void Intersection::setSource(const PrimitiveModel *m)
{
	model = m;
}
	
int Intersection::compare(const Ray &ray, const Intersection &i) const
{
	if (!model) return -1;
	if (!i.model) return 1;
	double d1 = point.d2(ray.getOrigin());
	double d2 = i.point.d2(ray.getOrigin());
	
	if (d1 < d2) return 1;
	if (d1 > d2) return -1;
	return 0;
}

Color Intersection::getColor(int depth) const
{
	if (model)
	{
		return model->colorAt(ray, point, depth - 1);
	}
	
	return Color(Vector(0.25, 0.6, 0.95));
	//return Color::BLACK;
}

const Point& Intersection::getPoint() const
{
	return point;
}

const PrimitiveModel* Intersection::getModel() const
{
	return model;
}
