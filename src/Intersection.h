#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "../third-party/point.h"

class Ray;
class PrimitiveModel;

class Intersection
{
public:
	Intersection();
	Intersection(PrimitiveModel *m, Point p);
	virtual ~Intersection();
	int compare(Ray &ray, Intersection &i);
private:
	Point point;
};

#endif /*INTERSECTION_H_*/
