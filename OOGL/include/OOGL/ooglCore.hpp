#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include "Vec2.hpp"
#include "../GLEW/glew.h"

namespace gl
{
	bool ooglInit();
	void ooglTerminate();

	void clear();
	void setAspectRatio(Vec2u);
	void setView(Vec2f);
	int  getTime();
}

#endif