#include <OOGL/Shader.hpp>
#include <OOGL/Core.hpp>

namespace
{
	const char* VERTEX_SHADER = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"uniform float viewAspect;"
	"uniform vec2 viewPosition;"
	"uniform vec2 position;"
	"uniform vec2 scale;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	vec2 coordinate = point * scale + position + viewPosition;"
	"	gl_Position = vec4(coordinate.x / viewAspect, coordinate.y, 0, 1);"
	"	UV = pointUV;"
	"}";

	const char* FRAGMENT_SHADER = 
	"#version 330 \n"
	"in vec2 UV;"
	"uniform vec4 viewColor;"
	"uniform vec4 color;"
	"out vec4 outColor;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	outColor = clamp((texture(sampler, UV).rgba) + color + viewColor, 0, 1);"
	"}";
	
	GLuint ID = 0;
	GLuint positionLocation = 0;
	GLuint scaleLocation = 0;
	GLuint colorLocation = 0;
}



namespace gl
{	
	namespace Shader
	{
		GLuint getID() { return ID; }
		GLuint getPositionLocation() { return positionLocation; }
		GLuint getScaleLocation() { return scaleLocation; }
		GLuint getColorLocation() { return colorLocation; }
	}

	namespace CorePrivate
	{
		void genShader()
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

			glShaderSource(vertexShader, 1, &VERTEX_SHADER, 0);
			glShaderSource(fragmentShader, 1, &FRAGMENT_SHADER, 0);

			glCompileShader(vertexShader);
			glCompileShader(fragmentShader);

			ID = glCreateProgram();
			glAttachShader(ID, vertexShader);
			glAttachShader(ID, fragmentShader);
			glLinkProgram(ID);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			glUseProgram(ID);

			positionLocation = glGetUniformLocation(ID, "position");
			scaleLocation = glGetUniformLocation(ID, "scale");
			colorLocation = glGetUniformLocation(ID, "color");
		}
		void destroyShader() {glDeleteProgram(ID);}
	}
}