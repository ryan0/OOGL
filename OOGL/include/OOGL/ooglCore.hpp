#ifndef OOGLCORE_HPP
#define OOGLCORE_HPP

#include <OOGL\Vec2.hpp>
#include "../GLEW/glew.h"

namespace oogl
{
	bool ooglInit();
	void ooglTerminate();

	void setAspectRatio(Vec2u);
	void setView(Vec2f);
}

#endif