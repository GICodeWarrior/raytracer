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

#include "Checker.h"

#include <math.h>

#include "../../third-party/point.h"

Checker::Checker(PrimitiveModel *s)
: Material(s), x(1), y(1), z(1)
{
}

Checker::Checker(PrimitiveModel *s, double sx, double sy, double sz)
: Material(s), x(sx), y(sy), z(sz)
{
}

Checker::~Checker()
{
}

Color Checker::colorAt(const Ray &r, const Point &p, int depth) const
{
	double diff = 1e-10;
	int Px = (int)floor(p.x / x + diff);
	int Py = (int)floor(p.y / y + diff);
	int Pz = (int)floor(p.z / z + diff);
	
	return (Px + Py + Pz) % 2 ? Color(255,255,0) : Color::RED;
}
