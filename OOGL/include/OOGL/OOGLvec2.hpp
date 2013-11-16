//////////////////////////////////////
//             Vec2                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLVEC2_HPP
#define OOGLVEC2_HPP

#include "../GLEW/glew.h"

namespace oogl
{
	template<class value>
	class Vec2
	{	
	public:
		value x,y;
	
		Vec2();
		Vec2(const Vec2&);
		Vec2(value inX, value inY);
	
		Vec2& operator=(const Vec2&);
		value magnitude();
		

		//Addition
		friend Vec2 operator+(const Vec2&, value);
		friend Vec2 operator+(value, const Vec2&);
		Vec2 operator+(const Vec2&);
		Vec2& operator+=(const Vec2&);
		Vec2& operator+=(value);


		//Multiplication
		friend Vec2 operator*(const Vec2&, value);
		friend Vec2 operator*(value, const Vec2&);
		Vec2 operator*(const Vec2&);
		Vec2& operator*=(const Vec2&);
		Vec2& operator*=(value);


		//Subtraction
		Vec2 operator-(const Vec2&);
		Vec2& operator-=(const Vec2&);
		Vec2 operator-(value);
		Vec2& operator-=(value);


		//Division
		Vec2 operator/(const Vec2&);
		Vec2& operator/=(const Vec2&);
		Vec2 operator/(value);
		Vec2& operator/=(value);
	};
}

#endif