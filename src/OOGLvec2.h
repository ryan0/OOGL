#ifndef OOGLVEC2_H
#define OOGLVEC2_H

#include <GLEW\glew.h>

namespace oogl
{
	class Vec2
	{	
	public:
		GLfloat x,y;
	
		Vec2();
		Vec2(const Vec2&);
		Vec2(float inX, float inY);
	
		Vec2& operator=(const Vec2&);
		float operator*(const Vec2&);
		float magnitude();
	
	
		Vec2 operator+(const Vec2& vec2);
		Vec2 operator-(const Vec2& vec2);
		Vec2 operator-(float z);
		Vec2 operator/(float z);


		friend Vec2 operator+(const Vec2& vec, float z);
		friend Vec2 operator+(float z, const Vec2& vec);
		friend Vec2 operator*(const Vec2& vec, float z);
		friend Vec2 operator*(float z, const Vec2& vec);

	
		Vec2& operator+=(const Vec2& vec2);
		Vec2& operator-=(const Vec2& vec2);
		Vec2& operator+=(float z);
		Vec2& operator-=(float z);
		Vec2& operator*=(float z);
		Vec2& operator/=(float z);
	};
}

#endif