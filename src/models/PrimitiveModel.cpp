#include "PrimitiveModel.h"
#include "../../third-party/point.h"

PrimitiveModel::PrimitiveModel()
{
}

PrimitiveModel::PrimitiveModel(Color c)
: color(c)
{
}

PrimitiveModel::~PrimitiveModel()
{
}

Color PrimitiveModel::colorAt(Point &p)
{
	return color;
}
