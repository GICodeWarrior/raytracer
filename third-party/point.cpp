//==================================================================
// Copyright 2002, softSurfer (www.softsurfer.com)
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from it's use.
// Users of this code must verify correctness for their application.
//==================================================================

#include "point.h"
#include "vector.h"
#include <math.h>

//==================================================================
// Point Class Methods
//==================================================================

//------------------------------------------------------------------
// IO stream
//------------------------------------------------------------------

// Write output Point in format: "(%f)", "(%f, %f)", or "(%f, %f, %f)"
ostream& Point::operator<<(ostream& output) const
{
	output << "(" << x << ", " << y << ", " << z << ")";
	return output;
}

//------------------------------------------------------------------
// Comparison
//------------------------------------------------------------------

int Point::operator==(const Point &Q) const
{
	return (x==Q.x && y==Q.y && z==Q.z);
}

int Point::operator!=(const Point &Q) const
{
	return (x!=Q.x || y!=Q.y || z!=Q.z);
}

int Point::near(const Point &Q, double diff) const
{
	return (fabs(x - Q.x) < diff &&
			fabs(y - Q.y) < diff &&
			fabs(z - Q.z) < diff);
}

//------------------------------------------------------------------
// Point Vector Operations
//------------------------------------------------------------------

Vector Point::operator-(const Point &Q) const  // Vector diff of Points
{
	return Vector(x-Q.x, y-Q.y, z-Q.z);
}

Point Point::operator+(const Vector &v) const  // +ve translation
{
	return Point(x+v.x, y+v.y, z+v.z);
}

Point Point::operator-(const Vector &v) const  // -ve translation
{
	return Point(x - v.x, y - v.y, z - v.z);
}

Point& Point::operator+=(const Vector &v)      // +ve translation
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Point& Point::operator-=(const Vector &v)      // -ve translation
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

//------------------------------------------------------------------
// Point Scalar Operations (convenient but often illegal)
//------------------------------------------------------------------

Point Point::operator*(double c) const  // Scalar multiplication
{
	return Point(c * x, c * y, c * z);
}

Point Point::operator/(double c) const  // Scalar division
{
	return Point(x/c, y/c, z/c);
}

//------------------------------------------------------------------
// Point Addition (also convenient but often illegal)
//------------------------------------------------------------------

Point Point::operator+(const Point &Q) const  // Point addition
{
	return Point(Q.x+x, Q.y+y, Q.z+z);
}

//------------------------------------------------------------------
// Distance between Points
//------------------------------------------------------------------

double Point::d(const Point &Q) const   // Euclidean distance
{
	double dx = x - Q.x;
	double dy = y - Q.y;
	double dz = z - Q.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

double Point::d2(const Point &Q) const  // Euclidean distance^2 (more efficient)
{
	double dx = x - Q.x;
	double dy = y - Q.y;
	double dz = z - Q.z;
	return (dx*dx + dy*dy + dz*dz);
}
