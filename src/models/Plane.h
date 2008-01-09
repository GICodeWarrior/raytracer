#ifndef PLANE_H_
#define PLANE_H_

#include "PrimitiveModel.h"
#include "../../third-party/vector.h"

class Plane : public PrimitiveModel
{
public:
	Plane(Vector n, double d, Color c);
	virtual ~Plane();
	Intersection intersect(Ray &ray);
protected:
	Plane(Color c);
	void setDimensions(Vector n, double d);
private:
	Vector normal;
	double distance;
};

#endif /*PLANE_H_*/
