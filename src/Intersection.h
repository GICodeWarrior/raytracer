#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "../third-party/point.h"
#include "models/PrimitiveModel.h"
#include "Ray.h"

class Ray;
class Color;

class Intersection
{
public:
	Intersection();
	Intersection(const PrimitiveModel *m, Ray r, Point p);
	virtual ~Intersection();
	int compare(const Ray &ray, const Intersection &i) const;
	Color getColor(int depth) const;
	const Point& getPoint() const;
	const PrimitiveModel* getModel() const;
private:
	const PrimitiveModel *model;
	Ray ray;
	Point point;
};

#endif /*INTERSECTION_H_*/
