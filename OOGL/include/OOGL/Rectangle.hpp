#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

namespace gl
{
	struct Rectangle : public Shape
	{
		Rectangle();
		Rectangle(Vec2f, Vec2f);
		Rectangle(Vec2f, GLfloat);

		virtual const VertexArray& getVA() const;
	};
}

#endif