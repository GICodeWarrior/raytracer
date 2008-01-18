#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../models/PrimitiveModel.h"

class Material : public PrimitiveModel
{
public:
	Material(PrimitiveModel *s);
	virtual ~Material();
	virtual Color colorAt(Point &p);
	virtual Intersection intersect(Ray& ray);
private:
	PrimitiveModel *subModel;
};

#endif /*MATERIAL_H_*/
