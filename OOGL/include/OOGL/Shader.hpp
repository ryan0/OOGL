#ifndef SHADER_HPP
#define SHADER_HPP

#include "../GLEW/glew.h"

namespace gl
{
	namespace Shader
	{		
		GLuint getID();
		GLuint getPositionLocation();
		GLuint getScaleLocation();
		GLuint getColorLocation();
		GLuint getAspectLocation();
		GLuint getViewLocation();
	};
}
#endif 