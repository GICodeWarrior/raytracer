#include "Transmission.h"

#include "../../third-party/vector.h"
#include "../Ray.h"
#include "../World.h"
#include "../Intersection.h"

Transmission::Transmission(PrimitiveModel *s, World *w, double t, double i)
: Material(s), world(w), transmissiveness(t), ior(i)
{
}

Transmission::~Transmission()
{
}

Color Transmission::colorAt(const Ray &r, const Point &p, int depth) const
{
	Vector color = Material::colorAt(r, p, depth).asVector();
	if (depth < 0) return color;
	
	Vector normal = Material::normalAt(p);
	
	double n = 1.0 / ior;

	if (normal * -r.getVector() < 0)
	{
		normal = -normal;
		n = ior;
	}
	
	double tir = n * sin(acos(-r.getVector() * normal));
	
	if (tir > 1)
	{
		Vector reflection = r.getVector() - 2 * normal * (r.getVector() * normal);
		reflection.normalize();
	
		Point origin = p + (reflection * 1e-5);
		Vector reflectColor = world->intersect(Ray(origin, reflection)).getColor(depth).asVector();
	
		color += reflectColor * transmissiveness;
	
		return color;
	}

	double offsetLength = tan(asin(tir));
	
	Vector subNormal = normal * -r.getVector() * normal;
	Vector offset = p + subNormal - (p - r.getVector());
	offset.normalize();
	offset *= offsetLength;
	
	Vector transmission = p - normal + offset - p;
	transmission.normalize();
	
	Point origin = p + (transmission * 1e-5);
	Vector transmitColor = world->intersect(Ray(origin, transmission)).getColor(depth).asVector();
	
	color += transmitColor * transmissiveness;
	
	return color;
}
