#ifndef OOGLVERTEXARRAY_HPP
#define OOGLVERTEXARRAY_HPP

#include "../GLEW/glew.h"
#include "OpenglObject.hpp"
#include "Vec2.hpp"
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
		VertexArray(const std::vector<Vertex>&);
		VertexArray(const Vec2f& inPosition, GLfloat inScale);
		VertexArray(const Vec2f& inPosition, const Vec2f& inScale);

		virtual void bind() const;
		virtual void destroy();

		void setPosition(const Vec2f&);
		void translate(const Vec2f&);
		Vec2f getPosition() const;
		void setScale(const Vec2f&);
		void scale(const Vec2f&);
		Vec2f getScale() const;
		int getDataSize() const;

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
		
		Vec2f point;
		Vec2f size;
		std::vector<Vertex> vertices;
		std::shared_ptr<VertexArrayHandle> vHandle;

		void gen();
		static void genRectangleVA();
		static void destroyRectangleVA();
	};
}
#endif 