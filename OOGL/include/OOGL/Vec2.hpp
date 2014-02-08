//////////////////////////////////////
//             Vec2                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLVEC2_HPP
#define OOGLVEC2_HPP

#include "../GLEW/glew.h"
#include <math.h>


namespace oogl
{
	template<class value>
	class Vec2
	{	
	public:
		value x,y;

		Vec2()						: x(0), y(0) {}
		Vec2(const Vec2& vec2)		: x(vec2.x), y(vec2.y) {}
		Vec2(value X, value Y)      : x(X), y(Y) {}

		Vec2& operator=(const Vec2& vec2)
		{
			if(this != &vec2)
			{
				x = vec2.x;
				y = vec2.y;
			}
			return *this;
		}


		value magnitude()
		{
			value sum = x * x + y * y;
			return sqrt(sum);
		}


		//Adition
		Vec2 operator+(const Vec2& vec2)	{ return Vec2(x + vec2.x, y + vec2.y); }
		Vec2& operator+=(const Vec2& vec2)	{ *this = *this + vec2; return *this;  }
		Vec2& operator+=(value z)			{ *this = *this + z; return *this;     }

		//Multiplication
		Vec2 operator*(const Vec2& vec2)	{ return Vec2(x * vec2.x, y * vec2.y); }
		Vec2& operator*=(const Vec2& vec2)	{ *this = *this * vec2; return *this;  }
		Vec2& operator*=(value z)			{ *this = *this * z; return *this;     }

		//Subtraction
		Vec2 operator-(const Vec2& vec2)	{ return Vec2(x - vec2.x, y - vec2.y); }
		Vec2& operator-=(const Vec2& vec2)	{ *this = *this - vec2; return *this;  }
		Vec2 operator-(value z)				{ return Vec2(x - z, y - z);           }
		Vec2& operator-=(value z)			{ *this = *this - z; return *this;     }

		//Division
		Vec2 operator/(const Vec2& vec2)	{ return Vec2(x / vec2.x, y / vec2.y); }
		Vec2& operator/=(const Vec2& vec2)	{ *this = *this / vec2; return *this;  }
		Vec2 operator/(value z)				{ return Vec2(x / z, y / z);           }
		Vec2& operator/=(value z)			{ *this = *this / z; return *this;     }
	};

	template<class value>
	Vec2<value> operator+(const Vec2<value>& vec2, value z)	
	{ return Vec2<value>(vec2.x + z, vec2.y + z); }

	template<class value>
	Vec2<value> operator+(value z, const Vec2<value>& vec2)	
	{ return Vec2<value>(vec2.x + z, vec2.y + z); }

	template<class value>
	Vec2<value> operator*(const Vec2<value>& vec2, value z)	
	{ return Vec2<value>(vec2.x * z, vec2.y * z); }

	template<class value>
	Vec2<value> operator*(value z, const Vec2<value>& vec2)	
	{ return Vec2<value>(vec2.x * z, vec2.y * z); }


	typedef Vec2<GLint>         Vec2i;
	typedef Vec2<GLuint>		Vec2u;
	typedef Vec2<GLfloat>       Vec2f;
}
#endif