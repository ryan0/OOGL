#ifndef OOGLENTITY_H
#define OOGLENTITY_H

#include <GLEW\glew.h>
#include "OOGLvec2.h"
#include "OOGLtexture.h"
#include "OOGLmodel.h"

namespace oogl
{
	enum ShaderType
	{
		NULL,
		NORMAL
	};

	class Entity
	{
		GLuint shaderID;
		Texture texture;
		Model model;
		bool visible;
	public:
	
		Entity(const Model&, const Texture&, ShaderType);
		Entity(Vec2[], const Texture&, ShaderType);
	};
}

#endif // !OOGLENTITY_H
