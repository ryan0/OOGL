//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

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
		Entity(const Entity&);
		Entity(const Model&, const Texture&, shaderType);
		~Entity();

		Entity& operator=(const Entity&);
		
		void visible(bool);
		void swapTexture(const Texture&);
		void setShader(shaderType);
		void setPosition(const Vec2&);
		Vec2 getPosition();
		void translate(const Vec2&);
		void scale(const Vec2&);
		void rotate(float);

		static void drawAll();

	private:
		static std::vector<Entity*> allEntities;

		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;

		uniformData uniforms;

		void draw();
		bool visibility;
	};
}
#endif