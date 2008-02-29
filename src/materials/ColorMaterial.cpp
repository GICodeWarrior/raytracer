#include "ColorMaterial.h"

ColorMaterial::ColorMaterial(Color c)
: color(c)
{
}

ColorMaterial::ColorMaterial(PrimitiveModel *s, Color c)
: Material(s), color(c)
{
}

ColorMaterial::~ColorMaterial()
{
}

Color ColorMaterial::colorAt(const Ray &r, const Point &p, int depth) const
{
	return color;
}
