//==================================================================
// Copyright 2002, softSurfer (www.softsurfer.com)
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from it's use.
// Users of this code must verify correctness for their application.
//==================================================================

#include "vector.h"
#include <math.h>

//==================================================================
// Vector Class Methods
//==================================================================

//------------------------------------------------------------------
//  Unary Ops
//------------------------------------------------------------------

// Unary minus
Vector Vector::operator-() const
{
	return Vector(-x, -y, -z);
}

//------------------------------------------------------------------
//  Scalar Ops
//------------------------------------------------------------------

// Scalar multiplication
Vector Vector::operator*(int c) const
{
	return Vector(x*c, y*c, z*c);
}

Vector Vector::operator*(double c) const
{
	return Vector(x*c, y*c, z*c);
}

// Scalar division
Vector Vector::operator/(int c) const
{
	return Vector(x/c, y/c, z/c);
}

Vector Vector::operator/(double c) const
{
	return Vector(x/c, y/c, z/c);
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

// Inner Dot Product
double Vector::operator*(const Vector &w) const
{
	return (x * w.x + y * w.y + z * w.z);
}

// 3D Exterior Cross Product
Vector Vector::operator^(const Vector &w) const
{
	return Vector(y*w.z - z*w.y, z*w.x - x*w.z, x*w.y - y*w.x);
}

//------------------------------------------------------------------
//  Shorthand Ops
//------------------------------------------------------------------

Vector& Vector::operator*=(double c)         // vector scalar mult
{
	x *= c;
	y *= c;
	z *= c;
	return *this;
}

Vector& Vector::operator/=(double c)         // vector scalar div
{
	x /= c;
	y /= c;
	z /= c;
	return *this;
}

Vector& Vector::operator+=(const Vector &w)         // vector increment
{
	x += w.x;
	y += w.y;
	z += w.z;
	return *this;
}

Vector& Vector::operator-=(const Vector &w)         // vector decrement
{
	x -= w.x;
	y -= w.y;
	z -= w.z;
	return *this;
}

Vector& Vector::operator^=(const Vector &w)         // 3D exterior cross product
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
Vector Vector::operator/( const Vector &w) const       // Vector division
{
	return Vector(x/w.x, y/w.y, z/w.z);
}

Vector& Vector::operator/=( const Vector &w)     // Vector division
{
	x /= w.x;
	y /= w.y;
	z /= w.z;
	return *this;
}

//------------------------------------------------------------------
// Vector Properties
//------------------------------------------------------------------

double Vector::len() const                // vector length
{
	return sqrt(x*x + y*y + z*z);
}
double Vector::len2() const              // vector length squared (faster)
{
	return (x*x + y*y + z*z);
}

//------------------------------------------------------------------
//  Special Operations
//------------------------------------------------------------------

void Vector::normalize()                       // convert to unit length
{
	double ln = sqrt( x*x + y*y + z*z );
	if (ln == 0) return;                    // do nothing for nothing
	x /= ln;
	y /= ln;
	z /= ln;
}
