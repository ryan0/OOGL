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
	class Entity
	{
	public:
		Entity();
		Entity(const Model&, const Texture&, ShaderType);
		~Entity();
		
		void visible(bool);
		void setPosition(const Vec2&);
		void translate(const Vec2&);
		void scale(const Vec2&);
		void rotate(float);

		void draw();
		static void drawAll();

	private:
		static std::vector<Entity*> allEntities;

		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;

		UniformData uniformData;

		bool visibility;
	};
}
#endif