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

#ifndef PRIMITIVEMODEL_H_
#define PRIMITIVEMODEL_H_

#include "Model.h"
#include "../Color.h"

class Point;

class PrimitiveModel : public Model
{
public:
	PrimitiveModel();
	PrimitiveModel(Color c);
	virtual ~PrimitiveModel();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
	virtual Vector normalAt(const Point &p) const = 0;
private:
	Color color;
};

#endif /*PRIMITIVEMODEL_H_*/
