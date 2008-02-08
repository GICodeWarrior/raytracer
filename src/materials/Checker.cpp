#include "Checker.h"

#include <math.h>

#include "../../third-party/point.h"

Checker::Checker(PrimitiveModel *s)
: Material(s), x(1), y(1), z(1)
{
}

Checker::Checker(PrimitiveModel *s, double x, double y, double z)
: Material(s), x(x), y(y), z(z)
{
}

Checker::~Checker()
{
}

Color Checker::colorAt(const Ray &r, const Point &p, int depth) const
{
	double diff = 1e-10;
	int Px = (int)floor(p.x / x + diff);
	int Py = (int)floor(p.y / y + diff);
	int Pz = (int)floor(p.z / z + diff);
	
	int color = (Px + Py + Pz) % 2;
	
	return color ? Color(255,255,0) : Color::RED;
}
