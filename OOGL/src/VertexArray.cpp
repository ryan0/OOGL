#include <OOGL/VertexArray.hpp>
#include <OOGL/Shader.hpp>

namespace gl
{
	struct VertexArray::VertexArrayHandle
	{
		GLuint ID, bufferID;
		VertexArrayHandle(GLuint id, GLuint buffID) : ID(id), bufferID(buffID) {}
		~VertexArrayHandle()
		{
			if(ID != 0)			glDeleteVertexArrays(1, &ID);	
			if(bufferID != 0)	glDeleteBuffers(1, &bufferID);
		}

		void bind() const { glBindVertexArray(ID); }
		static std::shared_ptr<VertexArrayHandle> gen(const std::vector<Vertex>& vertices)
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

			return std::shared_ptr<VertexArrayHandle>(new VertexArrayHandle(va, buffer));
		}
	};


	VertexArray::VertexArray()
		: dataSize(0), vaHandle(NULL) {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices) 
		: dataSize(inVertices.size()), vaHandle(VertexArrayHandle::gen(inVertices)) {}


	void VertexArray::bind() const {if(vaHandle) vaHandle->bind();}
	void VertexArray::destroy()    {vaHandle = NULL;}
	int VertexArray::getDataSize() const {return dataSize;}
}