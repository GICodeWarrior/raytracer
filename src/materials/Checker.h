#ifndef CHECKER_H_
#define CHECKER_H_

#include "Material.h"

class Checker : public Material
{
public:
	Checker(PrimitiveModel *s);
	Checker(PrimitiveModel *s, double x, double y, double z);
	virtual ~Checker();
	virtual Color colorAt(const Point &p) const;
private:
	double x, y, z;
};

#endif /*CHECKER_H_*/
