#ifndef SPHERE_H_
#define SPHERE_H_

#include "PrimitiveModel.h"
#include "../../third-party/point.h"

class Sphere : public PrimitiveModel
{
public:
	Sphere(Point o, double r, Color c);
	virtual ~Sphere();
	virtual Intersection intersect(const Ray& ray) const;
	virtual Vector normalAt(const Point &p) const;
private:
	Point origin;
	double radius;
};

#endif /*SPHERE_H_*/
