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

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "../third-party/point.h"
#include "models/PrimitiveModel.h"
#include "Ray.h"

class Ray;
class Color;

class Intersection
{
public:
	Intersection();
	Intersection(const PrimitiveModel *m, Ray r, Point p);
	virtual ~Intersection();
	int compare(const Ray &ray, const Intersection &i) const;
	Color getColor(int depth) const;
	const Point& getPoint() const;
	const PrimitiveModel* getModel() const;
private:
	const PrimitiveModel *model;
	Ray ray;
	Point point;
};

#endif /*INTERSECTION_H_*/
