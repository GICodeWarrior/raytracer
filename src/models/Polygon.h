#ifndef POLYGON_H_
#define POLYGON_H_

#include "Plane.h"
#include "../../third-party/point.h"
#include <vector>

class Polygon : public Plane
{
public:
	Polygon(vector<Point> v, Color c);
	virtual ~Polygon();
	Intersection intersect(const Ray &ray) const;
private:
	vector<Point> verticies;
};

#endif /*POLYGON_H_*/
