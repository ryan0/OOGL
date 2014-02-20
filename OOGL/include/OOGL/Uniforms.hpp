#ifndef OOGLUNIFORMS_HPP
#define OOGLUNIFORMS_HPP

#include "Vec2.hpp"

namespace gl
{
	struct Uniforms
	{
		Vec2f position;
		Vec2f scale;
		GLfloat r, g, b, a;

		Uniforms() : scale(1), r(0), g(0), b(0), a(0) {}

		Uniforms(Vec2f inPosition, Vec2f inScale)
			: position(inPosition), scale(inScale), r(0), g(0), b(0), a(0) {}

		void bind(); //defined in ooglCore.cpp
	}; 
}

#endif
