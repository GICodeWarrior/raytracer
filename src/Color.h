/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

#ifndef COLOR_H_
#define COLOR_H_

struct Pixel {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

class Vector;

class Color
{
public:
	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(Vector v);
	Color(Pixel &p);
	virtual ~Color();
	Pixel asPixel() const;
	Vector asVector() const;
	
	int operator==(const Color &c) const;
	
	const static Color BLACK;
	const static Color WHITE;
	const static Color RED;
	const static Color GREEN;
	const static Color BLUE;
private:
	unsigned char red, green, blue;
};

#endif /*COLOR_H_*/
