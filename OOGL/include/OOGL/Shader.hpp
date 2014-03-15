#ifndef SHADER_HPP
#define SHADER_HPP

#include "../GLEW/glew.h"
#include "Vec2.hpp"


namespace gl
{
	class Shader
	{	
		friend bool ooglInit();
		friend void ooglTerminate();

	private:
		Shader();
		static void genShader();
		static void destroyShader();

		static GLuint ID;
		static GLuint positionLocation;
		static GLuint scaleLocation;
		static GLuint colorLocation;
		static GLuint aspectLocation;
		static GLuint viewLocation;
		static Vec2u aspectRatio;
		static Vec2f view;

	public:
		static void setAspectRatio(Vec2u);
		static void setView(Vec2f);

		static GLuint getID() { return ID; }
		static GLuint getPositionLocation() { return positionLocation; }
		static GLuint getScaleLocation() { return scaleLocation; }
		static GLuint getColorLocation() { return colorLocation; }
		static GLuint getAspectLocation() { return aspectLocation; }
		static GLuint getViewLocation() { return viewLocation; }
	};
}

#endif 
