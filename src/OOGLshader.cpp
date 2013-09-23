#include "OOGLshader.h"
#include <iostream>


const char* NormalVertexShader = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	gl_Position = vec4(point, 0, 1);"
	"	UV = pointUV;"
	"}";


const char* NormalFragmentShader = 
	"#version 330 \n"
	"in vec2 UV;"
	"out vec4 color;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	color = texture(sampler, UV).rgba;"
	"}";

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