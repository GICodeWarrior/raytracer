#ifndef ONION_H_
#define ONION_H_

#include "Material.h"

class Onion : public Material
{
public:
	Onion(PrimitiveModel *s);
	virtual ~Onion();
	virtual Color colorAt(const Point &p) const;
};

#endif /*ONION_H_*/
