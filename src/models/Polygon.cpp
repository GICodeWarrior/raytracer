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
	return none;
}
