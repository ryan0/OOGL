#include <OOGL/Rectangle.hpp>
#include <OOGL/Vertex.hpp>
#include <vector>

namespace gl
{
	VertexArray Rectangle::vertexArray = VertexArray();

	Rectangle::Rectangle()
		: position(0, 0), scale(1, 1) {}

	Rectangle::Rectangle(const Rectangle& rectangle)
		: position(rectangle.position), scale(rectangle.scale) {}

	Rectangle::Rectangle(const Vec2f& inPosition, const Vec2f& inScale)
		: position(inPosition), scale(inScale) {}


	const VertexArray& Rectangle::getVertexArray() const
	{
		return vertexArray;
	}


	void Rectangle::genRectangle()
	{
		std::vector<Vertex> data(6, Vertex());
		data[0] = Vertex(-.5, -.5, 0, 1);	
		data[1] = Vertex(-.5,  .5, 0, 0);	
		data[2] = Vertex( .5,  .5, 1, 0);	
		data[3] = Vertex( .5,  .5, 1, 0);	
		data[4] = Vertex( .5, -.5, 1, 1);	
		data[5] = Vertex(-.5, -.5, 0, 1);	

		vertexArray = VertexArray(data);
	}
}