#include "OOGLvec2.h"
#include <math.h>

namespace oogl
{
	Vec2::Vec2()
	{
		x = 0;
		y = 0;
	}


	Vec2::Vec2(float inX, float inY)
	{
		x = inX;
		y = inY;
	}


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

	
	Vec2& Vec2::operator+=(const Vec2& vec2)		{ return *this = *this + vec2; }
	Vec2& Vec2::operator-=(const Vec2& vec2)		{ return *this = *this - vec2; }
	Vec2& Vec2::operator+=(float z)					{ return *this = *this + z; }
	Vec2& Vec2::operator-=(float z)					{ return *this = *this - z; }
	Vec2& Vec2::operator*=(float z)					{ return *this = *this * z; }
	Vec2&Vec2:: operator/=(float z)					{ return *this = *this / z; }


	Vec2 Vec2::operator+(const Vec2& vec2)			{ return Vec2(x + vec2.x, y + vec2.y); }
	Vec2 Vec2::operator-(const Vec2& vec2)			{ return Vec2(x - vec2.x, y - vec2.y); }
	Vec2 Vec2::operator-(float z)					{ return Vec2(x - z, y - z); }
	Vec2 Vec2::operator/(float z)					{ return Vec2(x / z, y / z); }


	Vec2 operator+(const Vec2& vec, float z)		{ return Vec2(vec.x + z, vec.y + z); }
	Vec2 operator+(float z, const Vec2& vec)		{ return Vec2(vec.x + z, vec.y + z); }
	Vec2 operator*(const Vec2& vec, float z)		{ return Vec2(vec.x * z, vec.y * z); }
	Vec2 operator*(float z, const Vec2& vec)		{ return Vec2(vec.x * z, vec.y * z); }
}