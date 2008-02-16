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

#ifndef PLANE_H_
#define PLANE_H_

#include "PrimitiveModel.h"
#include "../../third-party/vector.h"

class Plane : public PrimitiveModel
{
public:
	Plane(Vector n, double d, Color c);
	virtual ~Plane();
	virtual Intersection intersect(const Ray &ray) const;
	virtual Vector normalAt(const Point &p) const;
protected:
	Plane(Color c);
	void setDimensions(Vector &n, double d);
private:
	Vector normal;
	double distance;
};

#endif /*PLANE_H_*/
