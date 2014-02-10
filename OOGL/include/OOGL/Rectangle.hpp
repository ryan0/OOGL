#ifndef OOGLRECTANGLE_HPP
#define OOGLRECTANGLE_HPP

#include "ooglCore.hpp"
#include "VertexArray.hpp"
#include "Vec2.hpp"

namespace oogl
{
	class Rectangle
	{
		friend bool ooglInit();

	public:
		Vec2f position, scale;

		Rectangle();
		Rectangle(const Rectangle&);
		Rectangle(const Vec2f&, const Vec2f&);

		const VertexArray& getVertexArray() const;

	private:
		static VertexArray vertexArray;
		static void genRectangle();
	};
}
#endif // !OOGLRECTANGLE_HPP
