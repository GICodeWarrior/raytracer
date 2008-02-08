#include "Reflection.h"

#include "../../third-party/vector.h"
#include "../Ray.h"
#include "../World.h"
#include "../Intersection.h"

Reflection::Reflection(PrimitiveModel *s, World *w, double r)
: Material(s), world(w), reflectivity(r)
{
}

Reflection::~Reflection()
{
}

Color Reflection::colorAt(const Ray &r, const Point &p, int depth) const
{
	Vector color = Material::colorAt(r, p, depth).asVector();
	if (depth < 0) return color;
	
	Vector normal = Material::normalAt(p);
	
	Vector reflection = r.getVector() - 2 * normal * (r.getVector() * normal);
	reflection.normalize();
	
	Point origin = p + (reflection * 1e-5);
	Vector reflectColor = world->intersect(Ray(origin, reflection)).getColor(depth).asVector();
	
	color += reflectColor * reflectivity;
	
	return color;
}
