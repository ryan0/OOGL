#ifndef OOGLSHADER_HPP
#define OOGLSHADER_HPP

#include "Vec2.hpp"
#include "ooglCore.hpp"
#include "../GLEW/glew.h"

namespace oogl
{
	class Shader
		{
			friend bool ooglInit();
			friend void setAspectRatio(Vec2u);
			friend void setView(Vec2f);

		public:
			struct uniformData
			{
				Vec2f scale;
				Vec2f diplacement;
			};

			uniformData uniforms;

			Shader();
			Shader(const Shader&);
			Shader& operator=(const Shader&);

			void bind();

		private:
			static GLuint ID;
			static GLuint displacementLocation;
			static GLuint scaleLocation;
			static GLuint aspectLocation;
			static GLuint viewLocation;

			static Vec2<unsigned int> aspectRatio;
			static Vec2<GLfloat> view;

			static void genShader();
		};
}
#endif