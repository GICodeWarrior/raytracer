#include "Light.h"

Light::Light(Point p, Color c)
: origin(p), tint(c)
{
}

Light::~Light()
{
}
