#include <OOGL\Shader.hpp>

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
}

namespace gl
{
	GLuint Shader::ID = 0;
	GLuint Shader::positionLocation = 0;
	GLuint Shader::scaleLocation = 0;
	GLuint Shader::aspectLocation = 0;
	GLuint Shader::viewLocation = 0;
	GLuint Shader::colorLocation = 0;
	gl::Vec2u Shader::aspectRatio = gl::Vec2u(1, 1);
	gl::Vec2f Shader::view = gl::Vec2f(0, 0);

		
	void Shader::setAspectRatio(Vec2u newRatio)
	{
		aspectRatio = newRatio;
		glUniform1f(aspectLocation, (float)aspectRatio.x / (float)aspectRatio.y);
	}


	void Shader::setView(Vec2f newView)
	{
		view = newView;
		glUniform2f(viewLocation, view.x, view.y);
	}

	void Shader::genShader()
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

	void Shader::destroyShader()
	{
		glDeleteProgram(ID);
	}
}