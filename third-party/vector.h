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
	explicit Vector(Point p) : Point(p.x, p.y, p.z) {};
	Vector(double a, double b, double c) : Point(a,b,c) {};
	virtual ~Vector() {};

	//----------------------------------------------------------
	// IO streams and Comparisons: inherit from Point class

	//----------------------------------------------------------
	// Vector Unary Operations
	Vector operator-() const;               // unary minus

	//----------------------------------------------------------
	// Vector Scalar Operations
	Vector operator*(double) const;  // Scalar multiplication
	Vector operator/(double) const;  // Scalar division
	
	Vector& operator*=(double);      // vector scalar mult
	Vector& operator/=(double);      // vector scalar div

	//----------------------------------------------------------
	// Vector Arithmetic Operations
	Vector operator+(const Vector&) const;  // vector add
	Vector operator-(const Vector&) const;  // vector subtract
	double operator*(const Vector&) const;  // inner dot product
	Vector operator^(const Vector&) const;  // 3D exterior cross product

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
	void normalize();  // convert vector to unit length
};

#endif // SS_Vector_H
