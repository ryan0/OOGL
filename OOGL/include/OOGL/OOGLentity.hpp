//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "OOGLvec2.hpp"
#include "OOGLanimation.hpp"
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
		virtual Entity& operator=(const Entity&);
		~Entity();

		static void setAspectRatio(const Vec2<unsigned int>&);
		static void setView(const Vec2<GLfloat>&);

		void setPosition(const Vec2<GLfloat>&);
		void translate(const Vec2<GLfloat>&);
		const Vec2<GLfloat>& getPosition();

		void setScale(const Vec2<GLfloat>&);
		void scale(const Vec2<GLfloat>&);
		const Vec2<GLfloat>& getScale();

		void setTexture(const Texture&);
		virtual void draw();


	private:
		struct uniformData
		{
			Vec2<GLfloat> scale;
			Vec2<GLfloat> diplacement;
		};


		class Shader
		{
		public:
			uniformData uniforms;

			Shader();
			Shader(const Shader&);
			Shader& operator=(const Shader&);

			void bind();
			static void setAspectRatio(const Vec2<unsigned int>&);
			static void setView(const Vec2<GLfloat>&);

		private:
			static GLuint ID;
			static GLuint displacementLocation;
			static GLuint scaleLocation;
			static GLuint aspectLocation;
			static GLuint viewLocation;
			static bool shaderGenerated;

			static Vec2<unsigned int> aspectRatio;
			static Vec2<GLfloat> view;

			static void genShader();
		};



		GLuint ID, bufferID;
		Shader shader;
		Texture texture;
		Model model;
	};
}
#endif