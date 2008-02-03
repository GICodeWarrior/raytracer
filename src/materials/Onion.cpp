#include "Onion.h"

#include <math.h>

#include "../../third-party/point.h"

Onion::Onion(PrimitiveModel *s)
: Material(s)
{
}

Onion::~Onion()
{
}

Color Onion::colorAt(const Ray &r, const Point &p) const
{
	int color = (int)sqrt(p.x * p.x + p.y * p.y + p.z * p.z) % 2;
	return color ? Color(255,255,0) : Color::RED;
}
