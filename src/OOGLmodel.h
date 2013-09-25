#ifndef OOGLMODEL_H
#define OOGLMODEL_H

#include "OOGLvec2.h"
#include <GLEW\glew.h>
#include <vector>

namespace oogl
{
	class Entity;

	class Model
	{
		friend class Entity;

	public:
		Model();
		Model(const Model&);
		Model(const char*);
		Model(const Vec2&, float);
		Model(const std::vector<Vec2>&, const std::vector<Vec2>&);

		Model& operator=(const Model&);

	private:
		std::vector<GLfloat> data;
	};
}
#endif 