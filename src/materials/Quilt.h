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

#ifndef QUILT_H_
#define QUILT_H_

#include "Material.h"

class Quilt : public Material
{
public:
	explicit Quilt(PrimitiveModel *s);
	Quilt(PrimitiveModel *s, double x, double y, double z);
	virtual ~Quilt();
	virtual Vector normalAt(const Point &p) const;
private:
	double x, y, z;
	double c0, c1;
};

#endif /*QUILT_H_*/
