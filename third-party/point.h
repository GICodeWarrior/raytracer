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
	double x, y, z;

	//----------------------------------------------------------
	// Constructors
	Point() { x=y=z=0; }
	Point(double a, double b, double c) { x=a; y=b; z=c; }
	// Destructor
	virtual ~Point() {};

	//----------------------------------------------------------
	// Output stream
	ostream& operator<<(ostream&) const;

	//----------------------------------------------------------
	// Comparison (dimension must match, or not)
	int operator==(const Point&) const;
	int operator!=(const Point&) const;
	int near(const Point&, double diff = 1e-10) const;

	//----------------------------------------------------------
	// Point and Vector Operations (always valid) 
	Vector operator-(const Point&) const;   // Vector difference
	Point  operator+(const Vector&) const;  // +translate
	Point  operator-(const Vector&) const;  // -translate
	Point& operator+=(const Vector&);       // inc translate
	Point& operator-=(const Vector&);       // dec translate

	//----------------------------------------------------------
	// Point Scalar Operations (convenient but often illegal)

	// Scalar Multiplication
	Point operator*(double) const;
	// Scalar Division
	Point operator/(double) const;

	//----------------------------------------------------------
	// Point Addition (also convenient but often illegal)
	//    is not valid unless part of an affine sum.
	//    The programmer must enforce this (if they want to).
	Point operator+(const Point&) const;  // add points

	//----------------------------------------------------------
	// Point Relations
	double d(const Point&) const;         // Distance
	double d2(const Point&) const;        // Distance^2
};
#endif // SS_Point_H
