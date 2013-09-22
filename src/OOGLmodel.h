#ifndef OOGLMODEL_H
#define OOGLMODEL_H

#include <GLEW\glew.h>
#include <vector>
#include "OOGLvec2.h"

namespace oogl
{
	class Entity;

	class Model
	{
		friend class Entity;

	private:
		std::vector<GLfloat> data;

	public:
		Model() {}
		Model(const char*);
		Model(const std::vector<Vec2>&, const std::vector<Vec2>&);

		Model& operator=(const Model&);
	};
}
#endif 