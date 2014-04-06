#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include "../GLEW/glew.h"
#include "Vec2.hpp"
#include "Vec3.hpp"

namespace gl
{
	bool ooglInit();
	void ooglTerminate();
	void clear();
	int  getTime();

	GLfloat clampf(GLfloat f, GLfloat min, GLfloat max);
	Vec2f clampVec2f(Vec2f vec, GLfloat min, GLfloat max);
	Vec3f clampVec3f(Vec3f vec, GLfloat min, GLfloat max);
}

#endif