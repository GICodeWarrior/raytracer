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

#include "Quilt.h"
#include "../../third-party/vector.h"
#include <math.h>

Quilt::Quilt(PrimitiveModel *s)
: Material(s), x(1), y(1), z(1), c0(0.1), c1(0.0)
{
}

Quilt::Quilt(PrimitiveModel *s, double sx, double sy, double sz)
: Material(s), x(sx), y(sy), z(sz), c0(0.1), c1(0.0)
{
}

Quilt::~Quilt()
{
}

Vector Quilt::normalAt(const Point &p) const
{
	double diff = 1e-10;
	double Px = p.x / x + diff;
	double Py = p.y / y + diff;
	double Pz = p.z / z + diff;
	
	Vector normal = Material::normalAt(p);
	
	double Nx = fabs(normal.x);
	double Ny = fabs(normal.y);
	double Nz = fabs(normal.z);
	
	int ignore;
	if ((Nx > Ny) && (Nx > Nz)) ignore = 1;
	else if ((Ny > Nx) && (Ny > Nz)) ignore = 2;
	else ignore = 3;
	
	double u1 = Px;
	double v1 = Py;
	
	switch (ignore)
	{
		case 1: u1 = Pz; break;
		case 2: v1 = Pz; break;
	}
	
	double pi = 3.14159;
	double halfpi = 0.5 * 3.14159;
	u1 = tan(pi * u1 + halfpi) * c0;
	v1 = tan(pi * v1 + halfpi) * c0;
	
	switch (ignore)
	{
		case 1: normal.z += u1; normal.y += v1; break;
		case 2: normal.x += u1; normal.z += v1; break;
		case 3: normal.x += u1; normal.y += v1; break;
	}
	
	normal.normalize();
	return normal;
}
