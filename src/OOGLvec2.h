#ifndef OOGLVEC2_H
#define OOGLVEC2_H

class OOGLvec2
{
	
public:
	float x,y;

	OOGLvec2(float inX, float inY) { x = inX; y = inY; }

	OOGLvec2& operator=(const OOGLvec2&);
	float operator*(const OOGLvec2&);
	float magnitude();


	OOGLvec2 operator+(const OOGLvec2& vec2)	{ return OOGLvec2(x + vec2.x, y + vec2.y); }
	OOGLvec2 operator-(const OOGLvec2& vec2)	{ return OOGLvec2(x - vec2.x, y - vec2.y); }
	OOGLvec2 operator+(float z)					{ return OOGLvec2(x + z, y + z); }
	OOGLvec2 operator-(float z)					{ return OOGLvec2(x - z, y - z); }
	OOGLvec2 operator*(float z)					{ return OOGLvec2(x * z, y * z); }
	OOGLvec2 operator/(float z)				    { return OOGLvec2(x / z, y / z); }

	OOGLvec2& operator+=(const OOGLvec2& vec2)  { return *this = *this + vec2; }
	OOGLvec2& operator-=(const OOGLvec2& vec2)	{ return *this = *this - vec2; }
	OOGLvec2& operator+=(float z)				{ return *this = *this + z; }
	OOGLvec2& operator-=(float z)				{ return *this = *this - z; }
	OOGLvec2& operator*=(float z)				{ return *this = *this * z; }
	OOGLvec2& operator/=(float z)				{ return *this = *this / z; }
};



#endif
