#include "Light.h"

#include "World.h"

Light::Light(Point p, Color c, World *w)
: origin(p), tint(c), world(w)
{
}

Light::~Light()
{
}

bool Light::intersects(const Point &p) const
{
	return true;
}
