#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "../third-party/point.h"
#include "models/PrimitiveModel.h"

class Ray;
class Color;

class Intersection
{
public:
	Intersection();
	Intersection(PrimitiveModel *m, Point p);
	virtual ~Intersection();
	int compare(Ray &ray, Intersection &i);
	Color getColor();
private:
	PrimitiveModel *model;
	Point point;
};

#endif /*INTERSECTION_H_*/
