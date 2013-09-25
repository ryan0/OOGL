#include "OOGLshader.h"
#include "shaders.h"


namespace oogl
{
	std::vector<Shader> Shader::defaultShaders;


	Shader::Shader()
	{

	}


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
		
		defaultShaders.push_back(*this);
	}


	Shader::~Shader()
	{
		
	}


	bool Shader::setUpShaders()
	{
		bool success = true;

		Shader(NormalVertexShader, NormalFragmentShader);

		for(int i = 0; i < defaultShaders.size(); i++)
		{
			int compileStatus;
			glGetProgramiv(defaultShaders[i].ID, GL_LINK_STATUS, &compileStatus);

			if(compileStatus != GL_TRUE)
				success = false;
		}

		return success;
	}

	Shader& Shader::operator=(const Shader& shader)
	{
		ID = shader.ID;
		displacementLocation = shader.displacementLocation;
		return *this;
	}
}