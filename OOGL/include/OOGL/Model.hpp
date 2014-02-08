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
		Model(const Vec2f&, float);
		Model(const std::vector<Vec2f>&, const std::vector<Vec2f>&);

		Model& operator=(const Model&);

		int getDataSize();
		void genVertexArray(GLuint&, GLuint&);

	private:
		std::vector<GLfloat> data;
	};
}
#endif 