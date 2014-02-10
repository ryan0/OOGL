#ifndef OOGLVERTEXARRAY_HPP
#define OOGLVERTEXARRAY_HPP

//////////////////////////////////////
//           VertexArray                  //
//////////////////////////////////////
/*

*/

#include "Vec2.hpp"
#include "../GLEW/glew.h"
#include "Vertex.hpp"
#include <vector>
#include <string>

namespace oogl
{
	class VertexArray
	{

	public:
		VertexArray();
		VertexArray(const Vec2f&, float);
		VertexArray(const std::vector<Vertex>&);
		~VertexArray();

		VertexArray& operator=(const VertexArray&);
		Vertex& operator[](unsigned int);
		const Vertex& operator[](unsigned int) const;

		void genVertexArray();
		int getDataSize() const;
		void bind() const;
		void clear();

	private:
		GLuint ID, bufferID;
		std::vector<Vertex> vertices;
		bool isClear;
	};
}
#endif 