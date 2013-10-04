#include "OOGLvec2.hpp"
#include <math.h>

namespace oogl
{
	Vec2::Vec2() 
		: x(0), y(0) {}


	Vec2::Vec2(const Vec2& vec2) 
		: x(vec2.x), y(vec2.y) {}


	Vec2::Vec2(float inX, float inY) 
		: x(inX), y(inY) {}


	Vec2& Vec2::operator=(const Vec2& vec2)
	{
		if(this != &vec2)
		{
			x = vec2.x;
			y = vec2.y;
		}
		return *this;
	}


	float Vec2::magnitude()
	{
		float sum = x * x + y * y;
		return sqrt(sum);
	}

	//Adition
	Vec2 operator+(const Vec2& vec2, float z)	{ return Vec2(vec2.x + z, vec2.y + z); }
	Vec2 operator+(float z, const Vec2& vec2)	{ return Vec2(vec2.x + z, vec2.y + z); }
	Vec2 Vec2::operator+(const Vec2& vec2)		{ return Vec2(x + vec2.x, y + vec2.y); }
	Vec2& Vec2::operator+=(const Vec2& vec2)	{ *this = *this + vec2; return *this;  }
	Vec2& Vec2::operator+=(float z)				{ *this = *this + z; return *this;     }


	//Multiplication
	Vec2 operator*(const Vec2& vec2, float z)	{ return Vec2(vec2.x * z, vec2.y * z); }
	Vec2 operator*(float z, const Vec2& vec2)	{ return Vec2(vec2.x * z, vec2.y * z); }
	Vec2 Vec2::operator*(const Vec2& vec2)		{ return Vec2(x * vec2.x, y * vec2.y); }
	Vec2& Vec2::operator*=(const Vec2& vec2)	{ *this = *this * vec2; return *this;  }
	Vec2& Vec2::operator*=(float z)				{ *this = *this * z; return *this;     }


	//Subtraction
	Vec2 Vec2::operator-(const Vec2& vec2)		{ return Vec2(x - vec2.x, y - vec2.y); }
	Vec2& Vec2::operator-=(const Vec2& vec2)	{ *this = *this - vec2; return *this;  }
	Vec2 Vec2::operator-(float z)				{ return Vec2(x - z, y - z);           }
	Vec2& Vec2::operator-=(float z)				{ *this = *this - z; return *this;     }


	//Division
	Vec2 Vec2::operator/(const Vec2& vec2)		{ return Vec2(x / vec2.x, y / vec2.y); }
	Vec2& Vec2::operator/=(const Vec2& vec2)	{ *this = *this / vec2; return *this;  }
	Vec2 Vec2::operator/(float z)				{ return Vec2(x / z, y / z);           }
	Vec2& Vec2::operator/=(float z)				{ *this = *this / z; return *this;     }
}