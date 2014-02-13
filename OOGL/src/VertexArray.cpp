#include <OOGL/VertexArray.hpp>

namespace gl
{
	VertexArray::VertexArray() {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices)
		: vertices(inVertices)
	{
		genVertexArray();
	}


	VertexArray& VertexArray::operator=(const VertexArray& vertexArray)
	{
		glHandle = vertexArray.glHandle;
		vertices = vertexArray.vertices;
		return *this;
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


	void VertexArray::bind() const
	{
		if(glHandle) glBindVertexArray(glHandle->ID);
		else         glBindVertexArray(0);
	}


	void VertexArray::setNull()
	{
		glHandle = NULL;
	}

	void VertexArray::genVertexArray()
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

		glHandle.reset(new vaHandle(va, buffer));
	}
}