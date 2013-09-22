#ifndef OOGLVEC2_H
#define OOGLVEC2_H

namespace oogl
{
	class Vec2
	{	
	public:
		float x,y;
	
		Vec2(float inX, float inY)
		{
			x = inX;
			y = inY;
		}
	
		Vec2& operator=(const Vec2&);
		float operator*(const Vec2&);
		float magnitude();
	
	
		Vec2 operator+(const Vec2& vec2)	{ return Vec2(x + vec2.x, y + vec2.y); }
		Vec2 operator-(const Vec2& vec2)	{ return Vec2(x - vec2.x, y - vec2.y); }
		Vec2 operator-(float z)				{ return Vec2(x - z, y - z); }
		Vec2 operator/(float z)				{ return Vec2(x / z, y / z); }


		friend Vec2 operator+(const Vec2& vec, float z)		{ return Vec2(vec.x + z, vec.y + z); }
		friend Vec2 operator+(float z, const Vec2& vec)		{ return Vec2(vec.x + z, vec.y + z); }
		friend Vec2 operator*(const Vec2& vec, float z)		{ return Vec2(vec.x * z, vec.y * z); }
		friend Vec2 operator*(float z, const Vec2& vec)		{ return Vec2(vec.x * z, vec.y * z); }

	
		Vec2& operator+=(const Vec2& vec2)		{ return *this = *this + vec2; }
		Vec2& operator-=(const Vec2& vec2)		{ return *this = *this - vec2; }
		Vec2& operator+=(float z)				{ return *this = *this + z; }
		Vec2& operator-=(float z)				{ return *this = *this - z; }
		Vec2& operator*=(float z)				{ return *this = *this * z; }
		Vec2& operator/=(float z)				{ return *this = *this / z; }
	};
}

#endif