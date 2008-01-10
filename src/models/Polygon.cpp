#include "Polygon.h"

#include "../Intersection.h"
#include "../Ray.h"

Polygon::Polygon(vector<Point> v, Color c)
: Plane(c), verticies(v)
{
	Vector V1 = verticies[1] - verticies[0];
	Vector V2 = verticies[2] - verticies[1];
	Vector Vn = V1 ^ V2;
	
	Vector vertex(verticies[0].x, verticies[0].y, verticies[0].z);
	
	double distance = Vn * vertex;
	
	this->setDimensions(Vn, distance);
}

Polygon::~Polygon()
{
}

Intersection Polygon::intersect(Ray &ray)
{
	Intersection none;
	Intersection plane = Plane::intersect(ray);
	if (plane.compare(ray, none) < 0) return none;
	
	Point origin = plane.getPoint();
	Point cross1 = (verticies[0] + verticies[verticies.size() - 1]) / 2;
	Vector Vc = cross1 - origin;
	Vector Vt = origin - Point(0,0,0);
	int crosses = 1;
	
	for (unsigned int p1 = 0, p2 = 1; p2 < verticies.size(); p1++, p2++)
	{
		
	}
	
	return none;
}
