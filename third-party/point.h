//==================================================================
// Copyright 2002, softSurfer (www.softsurfer.com)
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from it's use.
// Users of this code must verify correctness for their application.
//==================================================================

#ifndef SS_Point_H
#define SS_Point_H

#include <iostream>
using namespace std;

class Vector;

//==================================================================
//  Point Class Definition
//==================================================================

class Point {
public:
	double x, y, z;      // z=0 for 2D, y=z=0 for 1D

	//----------------------------------------------------------
	// Lots of Constructors (add more as needed)
	Point() { x=y=z=0; }
	Point( double a, double b, double c) { x=a; y=b; z=c; }
	// Destructor
	virtual ~Point() {};

	//----------------------------------------------------------
	// Output stream
	friend ostream& operator<<( ostream&, Point);

	//----------------------------------------------------------
	// Comparison (dimension must match, or not)
	int operator==( Point) const;
	int operator!=( Point) const;
	int near(Point Q, double diff = 1e-10) const;

	//----------------------------------------------------------
	// Point and Vector Operations (always valid) 
	Vector operator-( Point) const;       // Vector difference
	Point  operator+( Vector) const;      // +translate
	Point  operator-( Vector) const;      // -translate
	Point& operator+=( Vector);     // inc translate
	Point& operator-=( Vector);     // dec translate

	//----------------------------------------------------------
	// Point Scalar Operations (convenient but often illegal)
	// using any type of scalar (int, float, or double)
	//    are not valid for points in general,
	//    unless they are 'affine' as coeffs of 
	//    a sum in which all the coeffs add to 1,
	//    such as: the sum (a*P + b*Q) with (a+b == 1).
	//    The programmer must enforce this (if they want to).

	// Scalar Multiplication
	Point operator*(int);
	Point operator*(double);
	// Scalar Division
	Point operator/(int);
	Point operator/(double);

	//----------------------------------------------------------
	// Point Addition (also convenient but often illegal)
	//    is not valid unless part of an affine sum.
	//    The programmer must enforce this (if they want to).
	friend Point operator+( Point, Point);     // add points

	//----------------------------------------------------------
	// Point Relations
	double d( const Point&) const;         // Distance
	double d2( const Point&) const;        // Distance^2
};
#endif // SS_Point_H
