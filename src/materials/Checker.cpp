#include "Checker.h"

#include <math.h>

#include "../../third-party/point.h"

Checker::Checker(PrimitiveModel *s)
: Material(s)
{
}

Checker::~Checker()
{
}

Color Checker::colorAt(const Point &p) const
{
	double diff = 1e-10;
	int x = (int)floor(p.x + diff) % 2;
	//if (p.x < 0) x -= 1;
	
	int y = (int)floor(p.y + diff) % 2;
	//if (p.y < 0) y -= 1;
	
	int z = (int)floor(p.z + diff) % 2;
	//if (p.z < 0) z -= 1;
	
	int color = (x + y + z) % 2;
	
	return color ? Color(255,255,0) : Color::RED;
}
