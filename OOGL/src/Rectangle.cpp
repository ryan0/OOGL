#include <OOGL\Rectangle.hpp>

namespace gl
{
	Rectangle::Rectangle() : Shape() {}
	Rectangle::Rectangle(Vec2f pos, Vec2f siz) : Shape(pos, siz) {}
	Rectangle::Rectangle(Vec2f pos, GLfloat scale) : Shape(pos, scale) {}

	static gl::VertexArray rectangleVA;

	const VertexArray& Rectangle::getVA() const
	{
		return rectangleVA;
	}


	namespace CorePrivate
	{
		void genRectangleVA()
		{
			std::vector<gl::Vertex> data(6, gl::Vertex());
			data[0] = gl::Vertex(-.5, -.5, 0, 1);	
			data[1] = gl::Vertex(-.5,  .5, 0, 0);	
			data[2] = gl::Vertex( .5,  .5, 1, 0);	
			data[3] = gl::Vertex( .5,  .5, 1, 0);	
			data[4] = gl::Vertex( .5, -.5, 1, 1);	
			data[5] = gl::Vertex(-.5, -.5, 0, 1);	

			rectangleVA = gl::VertexArray(data);
		}	
		void destroyRectangleVA() {rectangleVA.destroy();}
	}
}