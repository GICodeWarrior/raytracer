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
	bool intersects(const Point &p) const;
	Point getOrigin() const;
	Color getTint() const;
private:
	Point origin;
	Color tint;
	World *world;
};

#endif /*LIGHT_H_*/
