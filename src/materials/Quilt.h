#ifndef QUILT_H_
#define QUILT_H_

#include "Material.h"

class Quilt : public Material
{
public:
	Quilt(PrimitiveModel *s);
	Quilt(PrimitiveModel *s, double x, double y, double z);
	virtual ~Quilt();
	virtual Vector normalAt(const Point &p) const;
private:
	double x, y, z;
	double c0, c1;
};

#endif /*QUILT_H_*/
