#include "Color.h"

#include "../third-party/vector.h"

const Color Color::BLACK(0,0,0);
const Color Color::WHITE(255,255,255);
const Color Color::RED(255,0,0);
const Color Color::GREEN(0,255,0);
const Color Color::BLUE(0,0,255);

Color::Color()
{
}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
: red(r), green(g), blue(b)
{
}

Color::Color(Vector v)
{
	red = (unsigned char)min(v.x * 255, 255.0);
	green = (unsigned char)min(v.y * 255, 255.0);
	blue = (unsigned char)min(v.z * 255, 255.0);
}

Color::Color(Pixel &p)
{
	red = p.red;
	green = p.green;
	blue = p.blue;
}

Color::~Color()
{
}

Pixel Color::asPixel() const
{
	Pixel p;
	p.red = red;
	p.green = green;
	p.blue = blue;
	
	return p;
}

Vector Color::asVector() const
{
	Vector v(red / 255.0, green / 255.0, blue / 255.0);
	return v;
}
	
int Color::operator==(const Color &c) const
{
	return c.red == red && c.green == green &&	c.blue == blue;
}
