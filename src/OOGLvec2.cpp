#include "OOGLvec2.h"
#include <math.h>


OOGLvec2& OOGLvec2::operator=(const OOGLvec2& vec2)
{
	if(this != &vec2)
	{
		x = vec2.x;
		y = vec2.y;
	}
	return *this;
}

float OOGLvec2::operator*(const OOGLvec2& vec2)
{
	float xProduct = x * vec2.x;
	float yProduct = y * vec2.y;
	return xProduct + yProduct;
}

float OOGLvec2::magnitude()
{
	float sum = x * x + y * y;
	return sqrt(sum);
}

