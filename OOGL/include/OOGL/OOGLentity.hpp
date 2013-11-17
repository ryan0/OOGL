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
#include "../GLEW/glew.h"
#include <vector>

namespace oogl
{
	class Entity
	{
	public:
		Entity();
		Entity(const Entity&);
		Entity(const Model&, const Texture&);
		~Entity();

		static void setAspectRatio(const Vec2<unsigned int>&);

		virtual Entity& operator=(const Entity&);
	
		virtual void draw();
		void swapTexture(const Texture&);
		void setPosition(const Vec2<GLfloat>&);
		Vec2<GLfloat> getPosition();
		void translate(const Vec2<GLfloat>&);
		void scale(const Vec2<GLfloat>&);
		void rotate(float);


	private:
		struct uniformData
		{
			Vec2<GLfloat> scale;
			Vec2<GLfloat> diplacement;
			float rotation;
		};


	private:
		class Shader
		{
		public:
			uniformData uniforms;

			Shader();
			Shader(const Shader&);
			Shader& operator=(const Shader&);

			void bind();
			static void setAspectRatio(const Vec2<unsigned int>&);

		private:
			static GLuint ID;
			static GLuint displacementLocation;
			static GLuint scaleLocation;
			static Vec2<unsigned int> aspectRatio;
			static bool shaderGenerated;

			static void genShader();
		};


	private:
		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;
	};
}
#endif