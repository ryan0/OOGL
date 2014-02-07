#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include "../GLEW/glew.h"

namespace oogl
{
	bool ooglInit();
	void ooglTerminate();

	void setAspectRatio(int, int);
	void setView(GLfloat, GLfloat);
}

#endif