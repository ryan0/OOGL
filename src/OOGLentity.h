#ifndef OOGLENTITY_H
#define OOGLENTITY_H

#include <GLEW\glew.h>
#include "OOGLvec2.h"
#include "OOGLtexture.h"
#include "OOGLmodel.h"
#include "OOGLshader.h"

namespace oogl
{
	enum ShaderType
	{
		//Used as indices for Shader class's defaultShaders vector
		NORMAL = 0,
	};

	class Entity
	{
	private:
		Shader shader;
		Texture texture;
		Model model;
		bool visible;

	public:
		Entity() {}
		Entity(const Model&, const Texture&, ShaderType);
	};
}
#endif