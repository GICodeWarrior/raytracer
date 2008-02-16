//==================================================================
// Copyright 2002, softSurfer (www.softsurfer.com)
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from it's use.
// Users of this code must verify correctness for their application.
//==================================================================

#ifndef SS_Vector_H
#define SS_Vector_H

#include "point.h"

//==================================================================
//  Vector Class Definition
//==================================================================

class Vector : public Point {
public:
	// Constructors same as Point class
	Vector() : Point() {};
	Vector( double a, double b, double c) : Point(a,b,c) {};
	virtual ~Vector() {};

	//----------------------------------------------------------
	// IO streams and Comparisons: inherit from Point class

	//----------------------------------------------------------
	// Vector Unary Operations
	Vector operator-() const;               // unary minus

	//----------------------------------------------------------
	// Scalar Multiplication
	Vector operator*(double) const;
	// Scalar Division
	Vector operator/(double) const;

	//----------------------------------------------------------
	// Vector Arithmetic Operations
	Vector operator+(const Vector&) const;  // vector add
	Vector operator-(const Vector&) const;  // vector subtract
	double operator*(const Vector&) const;  // inner dot product
	Vector operator^(const Vector&) const;  // 3D exterior cross product

	Vector& operator*=(double);             // vector scalar mult
	Vector& operator/=(double);             // vector scalar div
	Vector& operator+=(const Vector&);      // vector increment
	Vector& operator-=(const Vector&);      // vector decrement
	Vector& operator^=(const Vector&);      // 3D exterior cross product

	//----------------------------------------------------------
	// Convienience Operations
	Vector operator/(const Vector&) const;  // Vector division
	Vector& operator/=(const Vector&);      // Vector division

	//----------------------------------------------------------
	// Vector Properties
	double len() const;
	double len2() const;

	//----------------------------------------------------------
	// Special Operations
	void normalize();                       // convert vector to unit length
};
#endif // SS_Vector_H
