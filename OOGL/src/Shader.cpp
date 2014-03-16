#include <OOGL/Shader.hpp>
#include <OOGL/Core.hpp>

namespace
{
	const char* VERTEX_SHADER = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"uniform float aspectRatio;"
	"uniform vec2 view;"
	"uniform vec2 position;"
	"uniform vec2 scale;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	vec2 coordinate = point * scale + position + view;"
	"	gl_Position = vec4(coordinate.x / aspectRatio, coordinate.y, 0, 1);"
	"	UV = pointUV;"
	"}";

	const char* FRAGMENT_SHADER = 
	"#version 330 \n"
	"in vec2 UV;"
	"uniform vec4 color;"
	"out vec4 outColor;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	outColor = clamp((texture(sampler, UV).rgba) + color, 0, 1);"
	"}";
	
	GLuint ID = 0;
	GLuint positionLocation = 0;
	GLuint scaleLocation = 0;
	GLuint aspectLocation = 0;
	GLuint viewLocation = 0;
	GLuint colorLocation = 0;
	gl::Vec2u aspectRatio = gl::Vec2u(1, 1);
	gl::Vec2f view = gl::Vec2f(0, 0);
}



namespace gl
{	
	void setAspectRatio(Vec2u newRatio)
	{
			aspectRatio = newRatio;
			glUniform1f(aspectLocation, (float)aspectRatio.x / (float)aspectRatio.y);
	}
	void setView(Vec2f newView)
	{
		view = newView;
		glUniform2f(viewLocation, view.x, view.y);
	}

	namespace Shader
	{
		GLuint getID() { return ID; }
		GLuint getPositionLocation() { return positionLocation; }
		GLuint getScaleLocation() { return scaleLocation; }
		GLuint getColorLocation() { return colorLocation; }
		GLuint getAspectLocation() { return aspectLocation; }
		GLuint getViewLocation() { return viewLocation; }
	}


	namespace Private
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
			aspectLocation = glGetUniformLocation(ID, "aspectRatio");
			viewLocation = glGetUniformLocation(ID, "view");
			colorLocation = glGetUniformLocation(ID, "color");

			glUniform1f(aspectLocation, (GLfloat)aspectRatio.x / (GLfloat)aspectRatio.y);
			glUniform2f(viewLocation, view.x, view.y);
		}
		void destroyShader() {glDeleteProgram(ID);}
	}
}