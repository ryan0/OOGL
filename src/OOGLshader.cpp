#include "OOGLshader.h"
#include "shaders.h"


namespace oogl
{
	std::vector<Shader> Shader::defaultShaders;


	Shader::Shader() {}


	Shader::Shader(const char* vertexShaderString, const char* fragmentShaderString)
	{
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderString, 0);
		glShaderSource(fragmentShader, 1, &fragmentShaderString, 0);

		glCompileShader(vertexShader);
		glCompileShader(fragmentShader);

		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		displacementLocation = glGetUniformLocation(ID, "displacement");
		scaleLocation = glGetUniformLocation(ID, "scale");
		
		defaultShaders.push_back(*this);
	}


	Shader::Shader(shaderType index)
	{
		*this = defaultShaders[index];
	}


	void Shader::setUpShaders()
	{
		Shader(NormalVertexShader, NormalFragmentShader);
	}


	Shader& Shader::operator=(const Shader& shader)
	{
		ID = shader.ID;
		displacementLocation = shader.displacementLocation;
		scaleLocation = shader.scaleLocation;
		return *this;
	}


	void Shader::bind(const uniformData& uniformValues)
	{
		glUseProgram(ID);
		glUniform2f(displacementLocation, uniformValues.diplacement.x, uniformValues.diplacement.y);
		glUniform2f(scaleLocation, uniformValues.scale.x, uniformValues.scale.y);
	}


	void Shader::aspectRatio(const Vec2& ratio)
	{
		float aspectRatio = ratio.x / ratio.y;
		for(int i = 0; i < defaultShaders.size(); i++)
		{
			glUseProgram(defaultShaders[i].ID);
			GLuint aspectRatioLocation = glGetUniformLocation(defaultShaders[i].ID, "aspectRatio");
			glUniform1f(aspectRatioLocation, aspectRatio);
		}
	}
}