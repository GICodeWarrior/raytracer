#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../models/PrimitiveModel.h"

class Material : public PrimitiveModel
{
public:
	Material(PrimitiveModel *s);
	virtual ~Material();
	virtual Intersection intersect(const Ray& ray) const;
	virtual Color colorAt(const Ray &r, const Point &p) const;
	virtual Vector normalAt(const Point &p) const;
protected:
	PrimitiveModel* getModel() const;
private:
	PrimitiveModel *subModel;
};

#endif /*MATERIAL_H_*/
