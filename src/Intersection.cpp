#include "Intersection.h"
#include "Ray.h"

#include "models/PrimitiveModel.h"

Intersection::Intersection()
: model(NULL)
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
	if (!model) return -1;
	if (!i.model) return 1;
	Point start = ray.getOrigin();
	double d1 = point.d2(start);
	double d2 = i.point.d2(start);
	
	if (d1 < d2) return 1;
	if (d1 > d2) return -1;
	return 0;
}

Color Intersection::getColor()
{
	if (model)
	{
		return model->colorAt(point);
	}
	
	return Color(0,0,0);
}

Point Intersection::getPoint()
{
	return point;
}
