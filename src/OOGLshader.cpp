#include "OOGLshader.h"
#include "shaders.h"
#include <iostream>


namespace oogl
{
	std::vector<Shader> Shader::defaultShaders;

	Shader::Shader(const char* vertexShaderString, const char* fragmentShaderString)
	{
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderString, 0);
		glCompileShader(vertexShader);

		glShaderSource(fragmentShader, 1, &fragmentShaderString, 0);
		glCompileShader(fragmentShader);

		GLuint program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		ID = program;
		defaultShaders.push_back(*this);
	}


	bool Shader::setUpShaders()
	{
		bool success = true;

		Shader normalShader(NormalVertexShader, NormalFragmentShader);

		for(int i = 0; i < defaultShaders.size(); i++)
		{
			int compileStatus;
			glGetProgramiv(defaultShaders[i].ID, GL_LINK_STATUS, &compileStatus);

			if(compileStatus != GL_TRUE)
				std::cout<< i << " shader compile error";
		}

		return success;
	}

	Shader& Shader::operator=(const Shader& shader)
	{
		ID = shader.ID;
		return *this;
	}
}