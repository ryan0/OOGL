#include "OOGLentity.h"

namespace oogl
{
	Entity::Entity(const Model& inModel, const Texture& inTex, ShaderType shaderType)
	{
		model = inModel;
		texture = inTex;

		switch(shaderType)
		{
		case NORMAL:

			break;
		}
	}
}