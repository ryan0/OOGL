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
		Vec2f point, size;

		VertexArray();
		VertexArray(const std::vector<Vertex>&);
		VertexArray(const Vec2f& inPosition, GLfloat inScale);
		VertexArray(const Vec2f& inPosition, const Vec2f& inScale);

		virtual void bind() const;
		virtual void destroy();
		int getDataSize() const;

	private:
		struct VertexArrayHandle;
		std::vector<Vertex> vertices;
		std::shared_ptr<const VertexArrayHandle> vaHandle;
	};
}
#endif 