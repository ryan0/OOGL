#include "OOGLmodel.h"

namespace oogl
{
	Model::Model(const char* filename)
	{

	}

	Model::Model(const std::vector<Vec2>& coordinates, const std::vector<Vec2>& uvs)
	{

	}

	Model& Model::operator=(const Model& model)
	{
		Data = model.Data;
		return *this;
	}
}