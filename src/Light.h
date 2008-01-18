#ifndef LIGHT_H_
#define LIGHT_H_

#include "../third-party/point.h"
#include "Color.h"

class World;

class Light
{
public:
	Light(Point p, Color c, World *w);
	virtual ~Light();
	bool intersects(Point &p) const;
private:
	Point origin;
	Color tint;
	World *world;
};

#endif /*LIGHT_H_*/
