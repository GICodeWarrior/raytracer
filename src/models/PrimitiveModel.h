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
	virtual Color colorAt(Point &p);
private:
	Color color;
};

#endif /*PRIMITIVEMODEL_H_*/
