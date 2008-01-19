#ifndef CHECKER_H_
#define CHECKER_H_

#include "Material.h"

class Checker : public Material
{
public:
	Checker(PrimitiveModel *s);
	virtual ~Checker();
	virtual Color colorAt(const Point &p) const;
};

#endif /*CHECKER_H_*/
