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
		friend void ooglEnd();

	private:
		static std::vector<Entity*> allEntities;

		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;

		bool visible;
		Vec2 position;

	public:
		Entity();
		Entity(const Model&, const Texture&, ShaderType);
		~Entity();
		
		void visibility(bool);
		void setPosition(const Vec2&);
		void translate(const Vec2&);

		void draw();
		static void drawAll();
	};
}
#endif