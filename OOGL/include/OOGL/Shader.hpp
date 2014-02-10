#ifndef OOGLSHADER_HPP
#define OOGLSHADER_HPP

#include "Vec2.hpp"
#include "ooglCore.hpp"
#include "../GLEW/glew.h"

namespace oogl
{ 
	struct Uniforms;

	class Shader
		{
			friend bool ooglInit();
			friend void setAspectRatio(Vec2u);
			friend void setView(Vec2f);

		public:
			static void bind(const Uniforms&);

		private:
			static GLuint ID;
			static GLuint positionLocation;
			static GLuint scaleLocation;
			static GLuint aspectLocation;
			static GLuint viewLocation;

			static Vec2u aspectRatio;
			static Vec2f view;

			static void genShader();
		};
}
#endif