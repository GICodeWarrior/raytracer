#include "Material.h"

#include "../Intersection.h"

Material::Material(PrimitiveModel *s)
{
}

Material::~Material()
{
}

Color Material::colorAt(Point &p)
{
	return subModel->colorAt(p);
}

Intersection Material::intersect(Ray& ray)
{
	return subModel->intersect(ray);
}
