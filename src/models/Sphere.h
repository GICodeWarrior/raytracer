#ifndef SPHERE_H_
#define SPHERE_H_

#include "PrimitiveModel.h"
#include "../../third-party/point.h"

class Sphere : public PrimitiveModel
{
public:
	Sphere(Point o, double r, Color c);
	virtual ~Sphere();
	Intersection intersect(Ray& ray);
private:
	Point origin;
	double radius;
};

#endif /*SPHERE_H_*/
