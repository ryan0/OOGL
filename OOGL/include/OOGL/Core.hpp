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
	void clear();
	int  getTime();

	void clampf(GLfloat& f, GLfloat min, GLfloat max);
	void clampVec2(Vec2f vec, GLfloat min, GLfloat max);
	void clampVec3(Vec3f vec, GLfloat min, GLfloat max);
}

#endif