#include <OOGL/OOGLvec2.hpp>
#include <math.h>

namespace oogl
{
	template<class value>
	Vec2<value>::Vec2() 
		: x(0), y(0) {}


	template<class value>
	Vec2<value>::Vec2(const Vec2<value>& vec2) 
		: x(vec2.x), y(vec2.y) {}


	template<class value>
	Vec2<value>::Vec2(value inX, value inY) 
		: x(inX), y(inY) {}


	template<class value>
	Vec2<value>& Vec2<value>::operator=(const Vec2<value>& vec2)
	{
		if(this != &vec2)
		{
			x = vec2.x;
			y = vec2.y;
		}
		return *this;
	}


	template<class value>
	value Vec2<value>::magnitude()
	{
		value sum = x * x + y * y;
		return sqrt(sum);
	}


	//Adition
	template<class value> 
	Vec2<value> operator+(const Vec2<value>& vec2, value z)	
	{ return Vec2(vec2.x + z, vec2.y + z); }


	template<class value> 
	Vec2<value> operator+(value z, const Vec2<value>& vec2)	
	{ return Vec2(vec2.x + z, vec2.y + z); }


	template<class value> 
	Vec2<value> Vec2<value>::operator+(const Vec2<value>& vec2)		
	{ return Vec2(x + vec2.x, y + vec2.y); }


	template<class value> 
	Vec2<value>& Vec2<value>::operator+=(const Vec2<value>& vec2)	
	{ *this = *this + vec2; return *this;  }


	template<class value> 
	Vec2<value>& Vec2<value>::operator+=(value z)				
	{ *this = *this + z; return *this;     }


	//Multiplication
	template<class value>
	Vec2<value> operator*(const Vec2<value>& vec2, value z)	
	{ return Vec2(vec2.x * z, vec2.y * z); }


	template<class value>
	Vec2<value> operator*(value z, const Vec2<value>& vec2)	
	{ return Vec2(vec2.x * z, vec2.y * z); }


	template<class value>
	Vec2<value> Vec2<value>::operator*(const Vec2<value>& vec2)		
	{ return Vec2(x * vec2.x, y * vec2.y); }


	template<class value>
	Vec2<value>& Vec2<value>::operator*=(const Vec2<value>& vec2)	
	{ *this = *this * vec2; return *this;  }


	template<class value>
	Vec2<value>& Vec2<value>::operator*=(value z)				
	{ *this = *this * z; return *this;     }


	//Subtraction
	template<class value>
	Vec2<value> Vec2<value>::operator-(const Vec2<value>& vec2)		
	{ return Vec2(x - vec2.x, y - vec2.y); }


	template<class value>
	Vec2<value>& Vec2<value>::operator-=(const Vec2<value>& vec2)	
	{ *this = *this - vec2; return *this;  }


	template<class value>
	Vec2<value> Vec2<value>::operator-(value z)				
	{ return Vec2(x - z, y - z);           }


	template<class value>
	Vec2<value>& Vec2<value>::operator-=(value z)				
	{ *this = *this - z; return *this;     }


	//Division
	template<class value>
	Vec2<value> Vec2<value>::operator/(const Vec2<value>& vec2)		
	{ return Vec2(x / vec2.x, y / vec2.y); }


	template<class value>
	Vec2<value>& Vec2<value>::operator/=(const Vec2<value>& vec2)	
	{ *this = *this / vec2; return *this;  }


	template<class value>
	Vec2<value> Vec2<value>::operator/(value z)				
	{ return Vec2(x / z, y / z);           }


	template<class value>
	Vec2<value>& Vec2<value>::operator/=(value z)				
	{ *this = *this / z; return *this;     }
}