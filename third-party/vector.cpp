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

  Copyright 2002 softSurfer (www.softsurfer.com)
  Copyright 2008 Rusty Burchfield
*/

#include "vector.h"
#include <math.h>

//==================================================================
// Vector Class Methods
//==================================================================

//------------------------------------------------------------------
//  Unary Ops
//------------------------------------------------------------------

Vector Vector::operator-() const  // Unary minus
{
	return Vector(-x, -y, -z);
}

//------------------------------------------------------------------
//  Scalar Ops
//------------------------------------------------------------------

Vector Vector::operator*(double c) const  // Scalar multiplication
{
	return Vector(x*c, y*c, z*c);
}

Vector Vector::operator/(double c) const  // Scalar division
{
	return Vector(x/c, y/c, z/c);
}

Vector& Vector::operator*=(double c)      // vector scalar mult
{
	x *= c;
	y *= c;
	z *= c;
	return *this;
}

Vector& Vector::operator/=(double c)      // vector scalar div
{
	x /= c;
	y /= c;
	z /= c;
	return *this;
}

//------------------------------------------------------------------
//  Arithmetic Ops
//------------------------------------------------------------------

Vector Vector::operator+(const Vector &w) const
{
	return Vector(x+w.x, y+w.y, z+w.z);
}

Vector Vector::operator-(const Vector &w) const
{
	return Vector(x - w.x, y - w.y, z - w.z);
}

//------------------------------------------------------------------
//  Products
//------------------------------------------------------------------

double Vector::operator*(const Vector &w) const  // Inner Dot Product
{
	return (x * w.x + y * w.y + z * w.z);
}

Vector Vector::operator^(const Vector &w) const  // 3D Exterior Cross Product
{
	return Vector(y*w.z - z*w.y, z*w.x - x*w.z, x*w.y - y*w.x);
}

//------------------------------------------------------------------
//  Shorthand Ops
//------------------------------------------------------------------

Vector& Vector::operator+=(const Vector &w)  // vector increment
{
	x += w.x;
	y += w.y;
	z += w.z;
	return *this;
}

Vector& Vector::operator-=(const Vector &w)  // vector decrement
{
	x -= w.x;
	y -= w.y;
	z -= w.z;
	return *this;
}

Vector& Vector::operator^=(const Vector &w)  // 3D exterior cross product
{
	double ox=x, oy=y, oz=z;
	x = oy * w.z - oz * w.y;
	y = oz * w.x - ox * w.z;
	z = ox * w.y - oy * w.x;
	return *this;
}

//------------------------------------------------------------------
//  Convienience Operations
//------------------------------------------------------------------
Vector Vector::operator/(const Vector &w) const // Vector division
{
	return Vector(x/w.x, y/w.y, z/w.z);
}

Vector& Vector::operator/=(const Vector &w)     // Vector division
{
	x /= w.x;
	y /= w.y;
	z /= w.z;
	return *this;
}

//------------------------------------------------------------------
// Vector Properties
//------------------------------------------------------------------

double Vector::len() const        // vector length
{
	return sqrt(x*x + y*y + z*z);
}
double Vector::len2() const       // vector length squared (faster)
{
	return (x*x + y*y + z*z);
}

//------------------------------------------------------------------
//  Special Operations
//------------------------------------------------------------------

void Vector::normalize()  // convert to unit length
{
	double ln = sqrt(x*x + y*y + z*z);
	if (ln == 0) return;  // do nothing for nothing
	x /= ln;
	y /= ln;
	z /= ln;
}
