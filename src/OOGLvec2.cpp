#include "OOGLvec2.h"
#include <math.h>

namespace oogl
{
	Vec2& Vec2::operator=(const Vec2& vec2)
	{
		if(this != &vec2)
		{
			x = vec2.x;
			y = vec2.y;
		}
		return *this;
	}

	float Vec2::operator*(const Vec2& vec2)
	{
		float xProduct = x * vec2.x;
		float yProduct = y * vec2.y;
		return xProduct + yProduct;
	}

	float Vec2::magnitude()
	{
		float sum = x * x + y * y;
		return sqrt(sum);
	}
}