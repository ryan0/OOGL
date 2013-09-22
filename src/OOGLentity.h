#ifndef OOGLENTITY_H
#define OOGLENTITY_H

#include <GLEW\glew.h>
#include <vector>
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
		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;
		bool visible;

		static std::vector<Entity> allEntities;
		void draw();

	public:
		Entity() {}
		Entity(const Model&, const Texture&, ShaderType);
		static void drawAll();
	};
}
#endif