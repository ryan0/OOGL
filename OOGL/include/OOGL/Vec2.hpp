#ifndef OOGLVEC2_HPP
#define OOGLVEC2_HPP

#include "../GLEW/glew.h"
#include <math.h>

namespace gl
{
	template<class T>
	struct Vec2
	{	
		T x, y;
		Vec2()					: x(0), y(0) {}
		Vec2(T Z)				: x(Z), y(Z) {}
		Vec2(T X, T Y)			: x(X), y(Y) {}

		T magnitude() const
		{
			T sum = x * x + y * y;
			return sqrt(sum);
		}

		
		//Adition
		Vec2 operator+(const Vec2& vec2) const	{ return Vec2(x + vec2.x, y + vec2.y);	}
		Vec2 operator+(T z)	const				{ return Vec2(x + z, y + z);			}
		Vec2& operator+=(const Vec2& vec2)		{ *this = *this + vec2; return *this;	}
		Vec2& operator+=(T z)					{ x += z; y += z; return *this;			}

		//Multiplication
		Vec2 operator*(const Vec2& vec2) const	{ return Vec2(x * vec2.x, y * vec2.y);	}
		Vec2 operator*(T z)	const				{ return Vec2(x * z, y * z);			}
		Vec2& operator*=(const Vec2& vec2)		{ *this = *this * vec2; return *this;	}
		Vec2& operator*=(T z)					{ x *= z; y *= z; return *this;			}

		//Subtraction
		Vec2 operator-(const Vec2& vec2) const	{ return Vec2(x - vec2.x, y - vec2.y);	}
		Vec2 operator-(T z) const				{ return Vec2(x - z, y - z);			}
		Vec2& operator-=(const Vec2& vec2)		{ *this = *this - vec2; return *this;	}
		Vec2& operator-=(T z)					{ *this = *this - z; return *this;		}

		//Division
		Vec2 operator/(const Vec2& vec2) const	{ return Vec2(x / vec2.x, y / vec2.y);	}
		Vec2 operator/(T z) const				{ return Vec2(x / z, y / z);			}
		Vec2& operator/=(const Vec2& vec2)		{ *this = *this / vec2; return *this;	}
		Vec2& operator/=(T z)					{ *this = *this / z; return *this;		}
	};

	template<class T>
	Vec2<T> operator+(T z, const Vec2<T>& vec2)
	{ return Vec2<T>(vec2.x + z, vec2.y + z); }

	template<class T>
	Vec2<T> operator*(T z, const Vec2<T>& vec2)	
	{ return Vec2<T>(vec2.x * z, vec2.y * z); }


	typedef Vec2<GLint>         Vec2i;
	typedef Vec2<GLuint>		Vec2u;
	typedef Vec2<GLfloat>       Vec2f;
}
#endif