#include <OOGL/VertexArray.hpp>

namespace gl
{
	static VertexArray rectangleVA;

	VertexArray::VertexArray() {}

	VertexArray::VertexArray(const Rectangle& rect) 
		: bounds(rect), vertices(rectangleVA.vertices),
		vHandle(rectangleVA.vHandle) {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices)
		: vertices(inVertices)
	{
		gen();
	}


	void VertexArray::setPosition(const Vec2f& newPosition)
	{
		bounds.point = newPosition;
	}
	void VertexArray::translate(const Vec2f& displacement)
	{
		bounds.point += displacement;
	}
	Vec2f VertexArray::getPosition() const
	{
		return bounds.point;
	}


	void VertexArray::setScale(const Vec2f& newScale)
	{
		bounds.size = newScale;
	}
	void VertexArray::scale(const Vec2f& newScale)
	{
		bounds.size *= newScale;
	}
	Vec2f VertexArray::getScale() const
	{
		return bounds.size;
	}


	Vertex& VertexArray::operator[](unsigned int index)
	{
		return vertices[index];
	}
	const Vertex& VertexArray::operator[](unsigned int index) const
	{
		return vertices[index];
	}
	int VertexArray::getDataSize() const
	{
		return vertices.size();
	}


	void VertexArray::destroy()
	{
		vHandle = NULL;
	}

	void VertexArray::gen()
	{
		GLuint va, buffer;
		glGenVertexArrays(1, &va);
		glBindVertexArray(va);

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER,buffer);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*) (sizeof(GLfloat) * 2) );

		vHandle.reset(new VertexArrayHandle(va, buffer));
	}


	void VertexArray::genRectangle()
	{
		std::vector<Vertex> data(6, Vertex());
		data[0] = Vertex(-.5, -.5, 0, 1);	
		data[1] = Vertex(-.5,  .5, 0, 0);	
		data[2] = Vertex( .5,  .5, 1, 0);	
		data[3] = Vertex( .5,  .5, 1, 0);	
		data[4] = Vertex( .5, -.5, 1, 1);	
		data[5] = Vertex(-.5, -.5, 0, 1);	

		rectangleVA = VertexArray(data);
	}

	void VertexArray::destroyRectangle()
	{
		rectangleVA .destroy();
	}
}