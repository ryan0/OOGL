#include "OOGLshader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace oogl
{
	Shader::Shader(const char* vertexFileLocation, const char* fragmentFileLocation)
	{
		ifstream vertexFile(vertexFileLocation);
		string vertexString;
		vertexFile >> vertexString;
		vertexFile.close();
		const char* vertexCstring = vertexString.c_str();

		ifstream fragmentFile(fragmentFileLocation);
		string fragmentString;
		fragmentFile >> fragmentString;
		fragmentFile.close();
		const char* fragmentCstring = fragmentString.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertexShader, 1, &vertexCstring, 0);
		glCompileShader(vertexShader);

		glShaderSource(fragmentShader, 1, &fragmentCstring, 0);
		glCompileShader(fragmentShader);

		GLuint program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		ID = program;
	}


	bool Shader::setUpShaders()
	{
		bool success = true;

		Shader normalShader("Shaders\\NormalVertexShader", "Shaders\\NormalFragmentShader");
		defaultShaders.push_back(normalShader);

		for(int i = 0; i < defaultShaders.size(); i++)
		{
			int compileStatus;
			glGetProgramiv(defaultShaders[i].ID, GL_LINK_STATUS, &compileStatus);

			if(compileStatus != GL_TRUE)
				success = false;
		}

		return success;
	}
}