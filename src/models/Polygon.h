#ifndef POLYGON_H_
#define POLYGON_H_

#include "PrimitiveModel.h"
#include "../../third-party/point.h"
#include <vector>

class Polygon : public PrimitiveModel
{
public:
	Polygon(vector<Point> v, Color c);
	virtual ~Polygon();
	Intersection intersect(Ray &ray);
private:
	vector<Point> verticies;
};

#endif /*POLYGON_H_*/
