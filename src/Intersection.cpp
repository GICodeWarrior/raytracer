#include "Intersection.h"
#include "Ray.h"

#include "models/PrimitiveModel.h"

Intersection::Intersection()
{
}

Intersection::Intersection(PrimitiveModel *m, Point p)
: model(m), point(p)
{
}

Intersection::~Intersection()
{
}

int Intersection::compare(Ray &ray, Intersection &i)
{
	Point start = ray.getPoint();
	double d1 = point.d2(start);
	double d2 = i.point.d2(start);
	
	if (d1 < d2) return 1;
	if (d1 > d2) return -1;
	return 0;
}

Color Intersection::getColor()
{
	return model->colorAt(point);
}
