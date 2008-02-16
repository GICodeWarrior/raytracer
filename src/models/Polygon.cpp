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

  Copyright 2008 Rusty Burchfield
*/

#include "Polygon.h"

#include "../Intersection.h"
#include "../Ray.h"

Polygon::Polygon(vector<Point> v, Color c)
: Plane(c), verticies(v)
{
	Vector V1 = verticies[1] - verticies[0];
	Vector V2 = verticies[2] - verticies[1];
	Vector Vn = V1 ^ V2;
	Vn.normalize();
	
	Vector vertex(verticies[0].x, verticies[0].y, verticies[0].z);
	
	double distance = Vn * vertex;
	
	this->setDimensions(Vn, distance);
}

Polygon::~Polygon()
{
}

Intersection Polygon::intersect(const Ray &ray) const
{
	Intersection none;
	Intersection plane = Plane::intersect(ray);
	if (plane.compare(ray, none) < 0) return none;
	
	Vector Vt = plane.getPoint() - Point(0,0,0);
	
	int ignore;
	
	Vector normal = normalAt(Point());
	double x = abs(normal.x);
	double y = abs(normal.y);
	double z = abs(normal.z);
	
	if ((x > y) && (x > z)) ignore = 1;
	else if ((y > x) && (y > z)) ignore = 2;
	else ignore = 3;
	
	int crosses = 0;
	
	bool done = false;
	vector<Point>::const_iterator p1 = verticies.begin();
	Point P1;
	Point P2 = *p1 - Vt;
	
	while (!done)
	{
		++p1;
		if (p1 == verticies.end())
		{
			p1 = verticies.begin();
			done = true;
		}
		
		P1 = P2;
		P2 = *p1 - Vt;
		
		double u1 = P1.x;
		double u2 = P2.x;
		double v1 = P1.y;
		double v2 = P2.y;
		
		switch (ignore)
		{
			case 1: u1 = P1.z; u2 = P2.z; break;
			case 2: v1 = P1.z; v2 = P2.z; break;
		}
		
		if ((u1 <= 0) && (u2 <= 0)) continue;
		if ((v1 < 0) && (v2 < 0)) continue;
		if ((v1 >= 0) && (v2 >= 0)) continue;
		
		if ((u1 > 0) && (u2 > 0))
		{
			++crosses;
			continue;
		}
		
		if ((u1 - u2) * v2 / (v2 - v1) + u2 > 0)
		{
			++crosses;	
		}
	}
	
	if (crosses % 2 == 1) return plane;
	
	return none;
}
