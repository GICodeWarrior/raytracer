#ifndef LIGHT_H_
#define LIGHT_H_

#include "../third-party/point.h"
#include "Color.h"

class Light
{
public:
	Light(Point p, Color c);
	virtual ~Light();
private:
	Point origin;
	Color tint;
};

#endif /*LIGHT_H_*/
