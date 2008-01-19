#include "Light.h"

#include "World.h"
#include "Ray.h"
#include "Intersection.h"

Light::Light(Point p, Color c, World *w)
: origin(p), tint(c), world(w)
{
}

Light::~Light()
{
}

bool Light::intersects(const Point &p) const
{
	Ray r(origin, p - origin);
	Intersection i = world->intersect(r);
	return i.getPoint().near(p);
}
