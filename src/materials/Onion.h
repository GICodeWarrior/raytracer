#ifndef ONION_H_
#define ONION_H_

#include "Material.h"

class Onion : public Material
{
public:
	Onion(PrimitiveModel *s);
	virtual ~Onion();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
};

#endif /*ONION_H_*/
