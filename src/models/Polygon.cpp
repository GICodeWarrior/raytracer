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
	
	Point origin = plane.getPoint();
	Vector Vt = origin - Point(0,0,0);
	
	int p1 = verticies.size() - 1;
	int ignore;
	
	double x = abs(getNormal().x);
	double y = abs(getNormal().y);
	double z = abs(getNormal().z);
	
	if ((x > y) && (x > z)) ignore = 1;
	else if ((y > x) && (y > z)) ignore = 2;
	else ignore = 3;
	
	int crosses = 0;
	
	for (unsigned int p2 = 0; p2 < verticies.size(); p2++)
	{
		Point P1 = verticies[p1] - Vt;
		Point P2 = verticies[p2] - Vt;
		
		p1 = p2;
		
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
