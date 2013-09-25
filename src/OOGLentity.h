#ifndef OOGLENTITY_H
#define OOGLENTITY_H

#include "OOGLvec2.h"
#include "OOGLtexture.h"
#include "OOGLmodel.h"
#include "OOGLshader.h"
#include <GLEW\glew.h>
#include <vector>

namespace oogl
{
	enum ShaderType
	{
		//Used as indices for Shader class's defaultShaders vector
		NORMAL = 0,
	};

	class Entity
	{
	public:
		Entity();
		Entity(const Model&, const Texture&, ShaderType);
		~Entity();
		
		void visible(bool);
		void setPosition(const Vec2&);
		void translate(const Vec2&);

		void draw();
		static void drawAll();

	private:
		static std::vector<Entity*> allEntities;

		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;

		Vec2 position;
		bool visibility;
	};
}
#endif