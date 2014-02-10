#ifndef OOGLUNIFORMS_HPP
#define OOGLUNIFORMS_HPP

#include "Vec2.hpp"

namespace gl
{
	struct Uniforms
	{
		Vec2f position;
		Vec2f scale;

		Uniforms() : scale(1, 1) {}

		Uniforms(Vec2f inPosition, Vec2f inScale)
			: position(inPosition), scale(inScale) {}
	}; 
}

#endif
