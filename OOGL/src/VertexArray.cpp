#include <OOGL/VertexArray.hpp>
#include <OOGL/Shader.hpp>

namespace gl
{
	static gl::VertexArray rectangleVA;
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
		: point(0), size(1), vertices(rectangleVA.vertices), vaHandle(rectangleVA.vaHandle) {}

	VertexArray::VertexArray(const std::vector<Vertex>& inVertices) 
		: point(0), size(1), vertices(inVertices), vaHandle(VertexArrayHandle::gen(inVertices)) {}

	VertexArray::VertexArray(const Vec2f& inPosition, GLfloat inScale)
		: point(inPosition), size(inScale), vertices(rectangleVA.vertices),
		vaHandle(rectangleVA.vaHandle) {}

	VertexArray::VertexArray(const Vec2f& inPosition, const Vec2f& inScale)
		: point(inPosition), size(inScale), vertices(rectangleVA.vertices),
		vaHandle(rectangleVA.vaHandle) {}


	void VertexArray::bind() const
	{
		glUniform2f(Shader::getPositionLocation(), point.x, point.y);
		glUniform2f(Shader::getScaleLocation(), size.x, size.y);
		if(vaHandle) vaHandle->bind();
	}
	void VertexArray::destroy() {vaHandle = NULL;}
	int VertexArray::getDataSize() const {return vertices.size();}


	namespace CorePrivate
	{
		void genDefaultVA()
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
		void destroyDefaultVA()
		{
			rectangleVA.destroy();
		}
	}
}