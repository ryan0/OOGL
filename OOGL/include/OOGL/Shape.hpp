#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "VertexArray.hpp"
#include "Vec2.hpp"

namespace gl
{
	struct Shape
	{
		Vec2f position, size;

		Shape() : size(1) {}
		Shape(Vec2f pos, Vec2f siz) : position(pos), size(siz) {}
		Shape(Vec2f pos, GLfloat scale) : position(pos), size(scale) {}

		virtual const VertexArray& getVA() const = 0;
	};
}

#endif