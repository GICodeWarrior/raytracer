#ifndef RAY_H_
#define RAY_H_

#include "../third-party/point.h"

class Vector;
class Intersection;

class Ray
{
public:
	Ray(Point p, Vector v);
	virtual ~Ray();
	Point getPoint();
private:
	Point point;
};

#endif /*RAY_H_*/
