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
