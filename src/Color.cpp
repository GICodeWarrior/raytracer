#include "Color.h"

Color::Color()
{
}

Color::Color(char r, char g, char b)
: red(r), green(g), blue(b)
{
}

Color::~Color()
{
}

Pixel Color::asPixel()
{
	Pixel p;
	p.red = red;
	p.green = green;
	p.blue = blue;
	
	return p;
}
