#ifndef OOGLVEC3_HPP
#define OOGLVEC3_HPP

#include "../GLEW/glew.h"
#include <math.h>

namespace gl
{
	template<class T>
	struct Vec3
	{	
		T  x,  y,  z;

		Vec3()					: x(0), y(0), z(0) {}
		Vec3(T A)				: x(A), y(A), z(A) {}
		Vec3(T X, T Y, T Z)		: x(X), y(Y), z(Z) {}


		T& r() {return x;}
		T& g() {return y;}
		T& b() {return z;}
		const T& g() const {return y;}
		const T& r() const {return x;}
		const T& b() const {return z;}


		T magnitude() const
		{
			T sum = x * x + y * y + z * z;
			return sqrt(sum);
		}

		
		//Adition
		Vec3 operator+(const Vec3& vec3) const	{ return Vec3(x + vec3.x, y + vec3.y, z + vec3.z); }
		Vec3 operator+(T a)	const				{ return Vec3(x + a, y + a, z + a);		}
		Vec3& operator+=(const Vec3& vec3)		{ *this = *this + vec3; return *this;	}
		Vec3& operator+=(T a)					{ x += a; y += a; z += a; return *this;	}

		//Multiplication
		Vec3 operator*(const Vec3& vec3) const	{ return Vec3(x * vec3.x, y * vec3.y, z * vec3.z); }
		Vec3 operator*(T a)	const				{ return Vec3(x * a, y * a, z * a);		}
		Vec3& operator*=(const Vec3& vec3)		{ *this = *this * vec3; return *this;	}
		Vec3& operator*=(T a)					{ x *= a; y *= a; z *= a; return *this;	}

		//Subtraction
		Vec3 operator-(const Vec3& vec3) const	{ return Vec3(x - vec3.x, y - vec3.y, z - vec3.z); }
		Vec3 operator-(T a)	const				{ return Vec3(x - a, y - a, z - a);		}
		Vec3& operator-=(const Vec3& vec3)		{ *this = *this - vec3; return *this;	}
		Vec3& operator-=(T a)					{ *this = *this - a; return *this;		}

		//Division
		Vec3 operator/(const Vec3& vec3) const	{ return Vec3(x / vec3.x, y / vec3.y, z / vec3.z); }
		Vec3 operator/(T a)	const				{ return Vec3(x / a, y / a, z / a);		}
		Vec3& operator/=(const Vec3& vec3)		{ *this = *this / vec3; return *this;	}
		Vec3& operator/=(T a)					{ *this = *this / a; return *this;		}
	};

	template<class T>
	Vec3<T> operator+(T a, const Vec3<T>& vec3)	
	{ return Vec3<T>(vec3.x + a, vec3.y + a, vec3.z + a); }

	template<class T>
	Vec3<T> operator*(T a, const Vec3<T>& vec3)	
	{ return Vec2<T>(vec3.x * a, vec3.y * a, vec3.z * a); }


	typedef Vec3<GLint>         Vec3i;
	typedef Vec3<GLuint>		Vec3u;
	typedef Vec3<GLfloat>       Vec3f;
}
#endif