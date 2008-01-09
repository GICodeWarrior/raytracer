#ifndef RAY_H_
#define RAY_H_

#include "../third-party/point.h"
#include "../third-party/vector.h"

class Intersection;

class Ray
{
public:
	Ray(Point p, Vector v);
	virtual ~Ray();
	Point getOrigin();
	Vector getVector();
private:
	Point point;
	Vector vector;
};

#endif /*RAY_H_*/
