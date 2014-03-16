#ifndef OOGLVERTEXARRAY_HPP
#define OOGLVERTEXARRAY_HPP

#include "../GLEW/glew.h"
#include "OpenglObject.hpp"
#include "Vec2.hpp"
#include <memory>
#include <vector>

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
		Vec2f point;
		Vec2f size;
		std::vector<Vertex> vertices;

		struct VertexArrayHandle;
		std::shared_ptr<const VertexArrayHandle> vaHandle;
	};
}
#endif 