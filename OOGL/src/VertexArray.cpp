#include <OOGL/VertexArray.hpp>
#include <OOGL/Shader.hpp>

namespace gl
{
	static gl::VertexArray rectangleVA;

	void VertexArray::genRectangleVA()
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

	void VertexArray::destroyRectangleVA()
	{
		rectangleVA.destroy();
	}



	VertexArray::VertexArray() 
		: OpenglObject(rectangleVA), point(0), size(1), vertices(rectangleVA.vertices) {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices)
		: point(0), size(1), vertices(inVertices) { gen(); }

	VertexArray::VertexArray(const Vec2f& inPosition, GLfloat inScale)
		: OpenglObject(rectangleVA), point(inPosition), size(inScale), 
		vertices(rectangleVA.vertices) {}

	VertexArray::VertexArray(const Vec2f& inPosition, const Vec2f& inScale)
		: OpenglObject(rectangleVA), point(inPosition), size(inScale), 
		vertices(rectangleVA.vertices) {}


	void VertexArray::bind() const
	{
		glUniform2f(Shader::getPositionLocation(), point.x, point.y);
		glUniform2f(Shader::getScaleLocation(), size.x, size.y);
		OpenglObject::bind();
	}

	void VertexArray::setPosition(const Vec2f& newPosition)
	{
		point = newPosition;
	}
	void VertexArray::translate(const Vec2f& displacement)
	{
		point += displacement;
	}
	Vec2f VertexArray::getPosition() const
	{
		return point;
	}


	void VertexArray::setScale(const Vec2f& newScale)
	{
		size = newScale;
	}
	void VertexArray::scale(const Vec2f& newScale)
	{
		size *= newScale;
	}
	Vec2f VertexArray::getScale() const
	{
		return size;
	}


	int VertexArray::getDataSize() const
	{
		return vertices.size();
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

		glHandles.push_back(std::shared_ptr<OpenglHandle>(new VertexArrayHandle(va, buffer)));
	}
}