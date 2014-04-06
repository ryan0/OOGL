#ifndef VIEW_HPP
#define VIEW_HPP

#include "Vec2.hpp"
#include "Vec3.hpp"

namespace gl
{
	namespace View
	{
		void setAspectRatio(Vec2u);
		void setPosition(Vec2f);
		void setColor(Vec3f color);
	}
}

#endif