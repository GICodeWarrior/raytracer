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
	Intersection(const PrimitiveModel *m, Point p);
	virtual ~Intersection();
	int compare(const Ray &ray, const Intersection &i) const;
	Color getColor() const;
	Point getPoint() const;
private:
	const PrimitiveModel *model;
	Point point;
};

#endif /*INTERSECTION_H_*/
