#ifndef COLOR_H_
#define COLOR_H_

class Color
{
public:
	Color();
	Color(int r, int g, int b);
	virtual ~Color();
private:
	int red, green, blue;
};

#endif /*COLOR_H_*/
