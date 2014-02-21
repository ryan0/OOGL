#ifndef OOGLVEC3_HPP
#define OOGLVEC3_HPP

#include "../GLEW/glew.h"
#include <math.h>


namespace gl
{
	template<class value>
	struct Vec3
	{	
		value  x, y, z;
		value &r, &g, &b;

		Vec3()						
			: x(0), y(0), z(0), r(x), g(y), b(z) {}

		Vec3(const Vec3& vec3)		
			: x(vec3.x), y(vec3.y), z(vec3.z), r(x), g(y), b(z) {}

		Vec3(value A)				
			: x(A), y(A), z(A), r(x), g(y), b(z) {}

		Vec3(value X, value Y, value Z) 
			: x(X), y(Y), z(Z), r(x), g(y), b(z) {}

		Vec3& operator=(const Vec3& vec3)
		{
			if(this != &vec3)
			{
				x = vec3.x;
				y = vec3.y;
				z = vec3.z;
			}
			return *this;
		}


		value magnitude()
		{
			value sum = x * x + y * y + z * z;
			return sqrt(sum);
		}

		
		//Adition
		Vec3 operator+(const Vec3& vec3)	{ return Vec3(x + vec3.x, y + vec3.y, z + vec3.z); }
		Vec3& operator+=(const Vec3& vec3)	{ *this = *this + vec3; return *this;  }
		Vec3& operator+=(value a)			{ x += a; y += a; z += a; return *this;}

		//Multiplication
		Vec3 operator*(const Vec3& vec3)	{ return Vec3(x * vec3.x, y * vec3.y, z * vec3.z); }
		Vec3& operator*=(const Vec3& vec3)	{ *this = *this * vec3; return *this;  }
		Vec3& operator*=(value a)			{ x *= a; y *= a; z *= a; return *this;}

		//Subtraction
		Vec3 operator-(const Vec3& vec3)	{ return Vec3(x - vec3.x, y - vec3.y, z - vec3.z); }
		Vec3& operator-=(const Vec3& vec3)	{ *this = *this - vec3; return *this;  }
		Vec3 operator-(value a)				{ return Vec3(x - a, y - a, z - a);    }
		Vec3& operator-=(value a)			{ *this = *this - a; return *this;     }

		//Division
		Vec3 operator/(const Vec3& vec3)	{ return Vec3(x / vec3.x, y / vec3.y, z / vec3.z); }
		Vec3& operator/=(const Vec3& vec3)	{ *this = *this / vec3; return *this;  }
		Vec3 operator/(value a)				{ return Vec3(x / a, y / a, z / a);    }
		Vec3& operator/=(value a)			{ *this = *this / a; return *this;     }
	};

	template<class value>
	Vec3<value> operator+(const Vec3<value>& vec3, value a)	
	{ return Vec3<value>(vec3.x + a, vec3.y + a, vec3.z + a); }

	template<class value>
	Vec3<value> operator+(value a, const Vec3<value>& vec3)	
	{ return Vec3<value>(vec3.x + a, vec3.y + a, vec3.z + a); }

	template<class value>
	Vec3<value> operator*(const Vec3<value>& vec3, value a)	
	{ return Vec3<value>(vec3.x * a, vec3.y * a, vec3.z * a); }

	template<class value>
	Vec3<value> operator*(value a, const Vec3<value>& vec3)	
	{ return Vec2<value>(vec3.x * a, vec3.y * a, vec3.z * a); }


	typedef Vec3<GLint>         Vec3i;
	typedef Vec3<GLuint>		Vec3u;
	typedef Vec3<GLfloat>       Vec3f;
}
#endif