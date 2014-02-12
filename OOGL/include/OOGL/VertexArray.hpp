#ifndef OOGLVERTEXARRAY_HPP
#define OOGLVERTEXARRAY_HPP

//////////////////////////////////////
//           VertexArray                  //
//////////////////////////////////////
/*

*/

#include "Vec2.hpp"
#include "../GLEW/glew.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

namespace gl
{
	struct Vertex
	{
		GLfloat X, Y, U, V;

		Vertex() {}

		Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v)
			: X(x), Y(y), U(u), V(v) {}
	};


	class VertexArray
	{

	public:
		VertexArray();
		VertexArray(const Vec2f&, float);
		VertexArray(const std::vector<Vertex>&);

		VertexArray& operator=(const VertexArray&);
		Vertex& operator[](unsigned int);
		const Vertex& operator[](unsigned int) const;

		void genVertexArray();
		int getDataSize() const;
		void bind() const;

	private:
		struct vaHandle
		{
			GLuint ID;
			GLuint bufferID;

			vaHandle(GLuint id, GLuint buffID)
				: ID(id), bufferID(buffID) {}

			~vaHandle()
			{
				if(ID != 0)
				{
					glDeleteBuffers(1, &bufferID);
					glDeleteVertexArrays(1, &ID);
				}

				std::cout<<"vaHandle deleted\n";
			}
		};

		std::shared_ptr<const vaHandle> glHandle;
		std::vector<Vertex> vertices;
	};
}
#endif 