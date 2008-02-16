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
