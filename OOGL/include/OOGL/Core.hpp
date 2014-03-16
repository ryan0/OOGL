#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include "../GLEW/glew.h"
#include "Vec2.hpp"
#include "Vec3.hpp"

namespace gl
{
	bool ooglInit();
	void ooglTerminate();
	void setAspectRatio(Vec2u);
	void setView(Vec2f);
	int  getTime();

	inline void clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	inline void clampf(GLfloat& f, GLfloat min, GLfloat max)
	{
		if(f < min) f = min;
		else if(f > max) f = max;
	}

	inline void clampVec2(Vec2f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
	}

	inline void clampVec3(Vec3f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
		clampf(vec.z, min, max);
	}
}

#endif