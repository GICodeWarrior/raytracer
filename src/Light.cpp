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
	const PrimitiveModel *model = i.getModel();
	if ((model) && (origin.d2(p + model->normalAt(p)) > origin.d2(p)))
	{
		return false;
	}
	return i.getPoint().near(p);
}

Point Light::getOrigin() const
{
	return origin;
}

Color Light::getTint() const
{
	return tint;
}
