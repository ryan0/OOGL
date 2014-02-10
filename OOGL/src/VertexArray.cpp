#include <OOGL/VertexArray.hpp>

namespace gl
{
	VertexArray::VertexArray() 
		:isClear(true) {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices)
		: vertices(inVertices), isClear(true)
	{
		genVertexArray();
	}

	VertexArray::~VertexArray()
	{
		clear();
	}



	VertexArray& VertexArray::operator=(const VertexArray& vertexArray)
	{
		clear();
		vertices = vertexArray.vertices;
		genVertexArray();
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



	void VertexArray::bind() const
	{
		glBindVertexArray(ID);
	}


	void VertexArray::clear()
	{
		if(isClear == false)
		{
			isClear = true;
			vertices.clear();
			glDeleteVertexArrays(1, &ID);
			glDeleteBuffers(1, &bufferID);
		}
	}


	int VertexArray::getDataSize() const
	{
		return vertices.size();
	}


	void VertexArray::genVertexArray()
	{
		clear();

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

		ID = va;
		bufferID = buffer;
		isClear = false;
	}
}