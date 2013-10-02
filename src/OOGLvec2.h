//////////////////////////////////////
//             Vec2                 //
//////////////////////////////////////
/*

*/

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
		float magnitude();
		

		//Addition
		friend Vec2 operator+(const Vec2&, float);
		friend Vec2 operator+(float, const Vec2&);
		Vec2 operator+(const Vec2&);
		Vec2& operator+=(const Vec2&);
		Vec2& operator+=(float);


		//Multiplication
		friend Vec2 operator*(const Vec2&, float);
		friend Vec2 operator*(float, const Vec2&);
		Vec2 operator*(const Vec2&);
		Vec2& operator*=(const Vec2&);
		Vec2& operator*=(float);


		//Subtraction
		Vec2 operator-(const Vec2&);
		Vec2& operator-=(const Vec2&);
		Vec2 operator-(float);
		Vec2& operator-=(float);


		//Division
		Vec2 operator/(const Vec2&);
		Vec2& operator/=(const Vec2&);
		Vec2 operator/(float);
		Vec2& operator/=(float);
	};
}

#endif