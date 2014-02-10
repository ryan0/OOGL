#ifndef OOGLVERTEX_HPP
#define OOGLVERTEX_HPP

#include "../GLEW/glew.h"

namespace oogl
{
	struct Vertex
	{
		GLfloat X, Y, U, V;

		Vertex() {}

		Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v)
			: X(x), Y(y), U(u), V(v) {}
	};
}

#endif // !OOGLVERTEX_HPP
