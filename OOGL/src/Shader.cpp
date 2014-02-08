#include <OOGL\Shader.hpp>


static const char* VERTEX_SHADER = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"uniform float aspectRatio;"
	"uniform vec2 view;"
	"uniform vec2 displacement;"
	"uniform vec2 scale;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	vec2 coordinate = point * scale + displacement + view;"
	"	gl_Position = vec4(coordinate.x / aspectRatio, coordinate.y, 0, 1);"
	"	UV = pointUV;"
	"}";


static const char* FRAGMENT_SHADER = 
	"#version 330 \n"
	"in vec2 UV;"
	"out vec4 color;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	vec4 testColor = texture(sampler, UV).rgba;"
	"	color = testColor;"
	"}";


namespace oogl
{
	GLuint Shader::ID = 0;
	GLuint Shader::displacementLocation = 0;
	GLuint Shader::scaleLocation = 0;
	GLuint Shader::aspectLocation = 0;
	GLuint Shader::viewLocation = 0;

	Vec2u Shader::aspectRatio = Vec2u(1, 1);
	Vec2f Shader::view = Vec2f(0, 0);
	

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

		displacementLocation = glGetUniformLocation(ID, "displacement");
		scaleLocation = glGetUniformLocation(ID, "scale");
		aspectLocation = glGetUniformLocation(ID, "aspectRatio");
		viewLocation = glGetUniformLocation(ID, "view");

		glUniform1f(aspectLocation, (GLfloat)aspectRatio.x / (GLfloat)aspectRatio.y);
		glUniform2f(viewLocation, view.x, view.y);
	}


	Shader::Shader()
	{
		uniforms.scale = Vec2f(1, 1);
	}


	Shader::Shader(const Shader& shader)
	{
		uniforms = shader.uniforms;
	}


	Shader& Shader::operator=(const Shader& shader)
	{
		uniforms = shader.uniforms;
		return *this;
	}


	void Shader::bind()
	{
		glUseProgram(ID);
		glUniform2f(displacementLocation, uniforms.diplacement.x, uniforms.diplacement.y);
		glUniform2f(scaleLocation, uniforms.scale.x, uniforms.scale.y);
	}
}