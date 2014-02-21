#ifndef OOGLUNIFORMS_HPP
#define OOGLUNIFORMS_HPP

#include "Vec2.hpp"
#include "Vec3.hpp"

namespace gl
{
	struct Uniforms
	{
		Vec2f position;
		Vec2f scale;
		Vec3f color;
		GLfloat alpha;

		Uniforms() : scale(1), alpha(0){}

		Uniforms(Vec2f inPosition, Vec2f inScale)
			: position(inPosition), scale(inScale), alpha(0){}

		void bind(); //defined in ooglCore.cpp
	}; 
}

#endif
