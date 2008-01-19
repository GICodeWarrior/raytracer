#ifndef COLOR_H_
#define COLOR_H_

struct Pixel {
	char red;
	char green;
	char blue;
};

class Color
{
public:
	Color();
	Color(char r, char g, char b);
	virtual ~Color();
	Pixel asPixel() const;
private:
	char red, green, blue;
};

#endif /*COLOR_H_*/
