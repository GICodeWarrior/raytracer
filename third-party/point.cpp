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
ostream& operator<<( ostream& output, const Point &P)
{
	output << "(" << P.x << ", " << P.y << ", " << P.z << ")";
	return output;
}

//------------------------------------------------------------------
// Comparison (note: dimension must compare)
//------------------------------------------------------------------

int Point::operator==( Point Q) const
{
	return (x==Q.x && y==Q.y && z==Q.z);
}

int Point::operator!=( Point Q) const
{
	return (x!=Q.x || y!=Q.y || z!=Q.z);
}

int Point::near(Point Q, double diff) const
{
	return (fabs(x - Q.x) < diff &&
			fabs(y - Q.y) < diff &&
			fabs(z - Q.z) < diff);
}

//------------------------------------------------------------------
// Point Vector Operations
//------------------------------------------------------------------

Vector Point::operator-( Point Q) const        // Vector diff of Points
{
	return Vector(x-Q.x, y-Q.y, z-Q.z);
}

Point Point::operator+( Vector v) const        // +ve translation
{
	return Point(x+v.x, y+v.y, z+v.z);
}

Point Point::operator-( Vector v) const        // -ve translation
{
	return Point(x - v.x, y - v.y, z - v.z);
}

Point& Point::operator+=( Vector v)        // +ve translation
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Point& Point::operator-=( Vector v)        // -ve translation
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

//------------------------------------------------------------------
// Point Scalar Operations (convenient but often illegal)
//        are not valid for points in general,
//        unless they are 'affine' as coeffs of 
//        a sum in which all the coeffs add to 1,
//        such as: the sum (a*P + b*Q) with (a+b == 1).
//        The programmer must enforce this (if they want to).
//------------------------------------------------------------------

Point Point::operator*( int c)
{
	return Point(c * x, c * y, c * z);
}

Point Point::operator*( double c)
{
	return Point(c * x, c * y, c * z);
}

Point Point::operator/( int c)
{
	return Point(x/c, y/c, z/c);
}

Point Point::operator/( double c)
{
	return Point(x/c, y/c, z/c);
}

//------------------------------------------------------------------
// Point Addition (also convenient but often illegal)
//    is not valid unless part of an affine sum.
//    The programmer must enforce this (if they want to).
//------------------------------------------------------------------

Point operator+( Point Q, Point R)
{
	return Point(Q.x+R.x, Q.y+R.y, Q.z+R.z);
}

//------------------------------------------------------------------
// Distance between Points
//------------------------------------------------------------------

double Point::d( const Point &Q) const {      // Euclidean distance
	double dx = x - Q.x;
	double dy = y - Q.y;
	double dz = z - Q.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

double Point::d2( const Point &Q) const {     // squared distance (more efficient)
	double dx = x - Q.x;
	double dy = y - Q.y;
	double dz = z - Q.z;
	return (dx*dx + dy*dy + dz*dz);
}

