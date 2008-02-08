#ifndef PRIMITIVEMODEL_H_
#define PRIMITIVEMODEL_H_

#include "Model.h"
#include "../Color.h"

class Point;

class PrimitiveModel : public Model
{
public:
	PrimitiveModel();
	PrimitiveModel(Color c);
	virtual ~PrimitiveModel();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
	virtual Vector normalAt(const Point &p) const = 0;
private:
	Color color;
};

#endif /*PRIMITIVEMODEL_H_*/
