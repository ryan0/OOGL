#ifndef OOGLRECTANGLE_HPP
#define OOGLRECTANGLE_HPP

#include "ooglCore.hpp"
#include "Vec2.hpp"

namespace gl
{
	struct Rectangle
	{
	public:
		Vec2f point;
		Vec2f size;

	Rectangle::Rectangle()
		: point(0), size(1) {}

	Rectangle::Rectangle(const Vec2f& inPosition, GLfloat inScale)
		: point(inPosition), size(inScale) {}

	Rectangle::Rectangle(const Vec2f& inPosition, const Vec2f& inScale)
		: point(inPosition), size(inScale) {}
	};
}
#endif // !OOGLRECTANGLE_HPP
