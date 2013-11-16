//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "OOGLvec2.hpp"
#include "OOGLtexture.hpp"
#include "OOGLmodel.hpp"
#include "OOGLshader.hpp"
#include "../GLEW/glew.h"
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

		virtual Entity& operator=(const Entity&);
	
		virtual void draw();
		void swapTexture(const Texture&);
		void setShader(shaderType);
		void setPosition(const Vec2<GLfloat>&);
		Vec2<GLfloat> getPosition();
		void translate(const Vec2<GLfloat>&);
		void scale(const Vec2<GLfloat>&);
		void rotate(float);


	private:
		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;

		uniformData uniforms;
	};
}
#endif