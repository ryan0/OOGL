#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include "../GLEW/glew.h"

namespace gl
{
	bool ooglInit();
	void ooglTerminate();
	void clear();
	void clampf(GLfloat& f, GLfloat min, GLfloat max);
	int  getTime();
}

#endif