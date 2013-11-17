#include <OOGL\OOGLentity.hpp>


static const char* VERTEX_SHADER = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"uniform float aspectRatio;"
	"uniform vec2 displacement;"
	"uniform vec2 scale;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	vec2 coordinate = point * scale + displacement;"
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
	"	if(testColor.a < .5) discard;"
	"	color = testColor;"
	"}";


namespace oogl
{
	GLuint Entity::Shader::ID = 0;
	GLuint Entity::Shader::displacementLocation = 0;
	GLuint Entity::Shader::scaleLocation = 0;
	Vec2<unsigned int> Entity::Shader::aspectRatio = Vec2<unsigned int>(1, 1);
	bool Entity::Shader::shaderGenerated = false;
	

	void Entity::Shader::genShader()
	{
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

		GLuint aspectRatioLocation = glGetUniformLocation(ID, "aspectRatio");
		glUniform1f(aspectRatioLocation, (float)aspectRatio.x / (float)aspectRatio.y);

		shaderGenerated = true;
	}


	void Entity::Shader::setAspectRatio(const Vec2<unsigned int>& newRatio)
	{
		aspectRatio = newRatio;

		GLuint aspectRatioLocation = glGetUniformLocation(ID, "aspectRatio");
		glUniform1f(aspectRatioLocation, (float)aspectRatio.x / (float)aspectRatio.y);

	}


	Entity::Shader::Shader()
	{
		if(!shaderGenerated)
			genShader();

		uniforms.scale = Vec2<GLfloat>(1, 1);
	}


	Entity::Shader::Shader(const Shader& shader)
	{
		uniforms = shader.uniforms;
	}


	Entity::Shader& Entity::Shader::operator=(const Shader& shader)
	{
		uniforms = shader.uniforms;
		return *this;
	}


	void Entity::Shader::bind()
	{
		glUseProgram(ID);
		glUniform2f(displacementLocation, uniforms.diplacement.x, uniforms.diplacement.y);
		glUniform2f(scaleLocation, uniforms.scale.x, uniforms.scale.y);
	}
}