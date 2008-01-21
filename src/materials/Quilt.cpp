#include "Quilt.h"

#include "../../third-party/vector.h"

Quilt::Quilt(PrimitiveModel *s)
: Material(s), x(1), y(1), z(1), c0(0.1), c1(0.0)
{
}

Quilt::Quilt(PrimitiveModel *s, double x, double y, double z)
: Material(s), x(x), y(y), z(z), c0(0.1), c1(0.0)
{
}

Quilt::~Quilt()
{
}

Vector Quilt::normalAt(const Point &p) const
{
	double diff = 1e-10;
	double Px = p.x / x + diff;
	double Py = p.y / y + diff;
	double Pz = p.z / z + diff;
	
	Vector normal = Material::normalAt(p);
	
	double Nx = abs(normal.x);
	double Ny = abs(normal.y);
	double Nz = abs(normal.z);
	
	int ignore;
	if ((Nx > Ny) && (Nx > Nz)) ignore = 1;
	else if ((Ny > Nx) && (Ny > Nz)) ignore = 2;
	else ignore = 3;
	
	double u1 = Px;
	double v1 = Py;
	
	switch (ignore)
	{
		case 1: u1 = Pz; break;
		case 2: v1 = Pz; break;
	}
	
	double pi = 3.14159;
	double halfpi = 0.5 * 3.14159;
	u1 = tan(pi * u1 + halfpi) * c0;
	v1 = tan(pi * v1 + halfpi) * c0;
	
	//double cutoff = 1.0e10;
	//u1 = max(min(u1, cutoff), -cutoff);
	//v1 = max(min(v1, cutoff), -cutoff);
	
	switch (ignore)
	{
		case 1: normal.z += u1; normal.y += v1; break;
		case 2: normal.x += u1; normal.z += v1; break;
		case 3: normal.x += u1; normal.y += v1; break;
	}
	
	normal.normalize();
	return normal;
}
