#ifndef OOGLVERTEXARRAY_HPP
#define OOGLVERTEXARRAY_HPP


#include "Rectangle.hpp"
#include "OpenglObject.hpp"
#include "../GLEW/glew.h"
#include <memory>
#include <vector>
#include <string>

namespace gl
{
	struct Vertex
	{
		GLfloat X, Y, U, V;

		Vertex() {}

		Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v)
			: X(x), Y(y), U(u), V(v) {}
	};

	class VertexArray : public OpenglObject
	{
		friend bool ooglInit();
		friend void ooglTerminate();

	public:
		VertexArray();
		VertexArray(const Rectangle&);
		VertexArray(const std::vector<Vertex>&);

		void setPosition(const Vec2f&);
		void translate(const Vec2f&);
		Vec2f getPosition() const;
		void setScale(const Vec2f&);
		void scale(const Vec2f&);
		Vec2f getScale() const;

		Vertex& operator[](unsigned int);
		const Vertex& operator[](unsigned int) const;
		int getDataSize() const;
		void gen();

		virtual void bind() const;
		virtual void destroy();

	private:
		struct VertexArrayHandle
		{
			GLuint ID;
			GLuint bufferID;
			VertexArrayHandle(GLuint id, GLuint buffID) : ID(id), bufferID(buffID) {}
			virtual ~VertexArrayHandle()
			{
				if(ID != 0 ) glDeleteVertexArrays(1, &ID);	
				if(bufferID != 0)	glDeleteBuffers(1, &bufferID);
			}
		};

		Rectangle bounds;
		std::vector<Vertex> vertices;
		std::shared_ptr<VertexArrayHandle> vHandle;

		static void genRectangle();
		static void destroyRectangle();
	};
}
#endif 