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
	// Comparison
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
	Point operator*(double) const;  // Scalar multiplication
	Point operator/(double) const;  // Scalar division

	//----------------------------------------------------------
	// Point Addition (also convenient but often illegal)
	Point operator+(const Point&) const;  // Point addition

	//----------------------------------------------------------
	// Distances
	double d(const Point&) const;   // Distance
	double d2(const Point&) const;  // Distance^2 (more efficient)
};

#endif // SS_Point_H
