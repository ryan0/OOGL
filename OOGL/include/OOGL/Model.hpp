#ifndef OOGLMODEL_HPP
#define OOGLMODEL_HPP

//////////////////////////////////////
//           Model                  //
//////////////////////////////////////
/*

*/

#include "Vec2.hpp"
#include "../GLEW/glew.h"
#include <vector>
#include <string>

namespace oogl
{
	class Model
	{

	public:
		Model();
		Model(const Model&);
		Model(std::string);
		Model(const Vec2<GLfloat>&, float);
		Model(const std::vector<Vec2<GLfloat>>&, const std::vector<Vec2<GLfloat>>&);

		Model& operator=(const Model&);

		int getDataSize();
		void genVertexArray(GLuint&, GLuint&);

	private:
		std::vector<GLfloat> data;
	};
}
#endif 