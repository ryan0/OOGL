#include <OOGL/ooglCore.hpp>
#include <OOGL/OOGLshader.hpp>
#include <GLEW/glew.h>



namespace oogl
{
	bool ooglInit()
	{
		bool setupSuccess = true;

		glewExperimental = GL_TRUE; 
		if(glewInit() != GLEW_OK)
			setupSuccess = false;
	
		Shader::setUpShaders();

		setAspectRatio(1, 1);

		return setupSuccess;
	}


	void ooglTerminate()
	{
		
	}


	void setAspectRatio(float x, float y)
	{
		float aspectRatio = x / y;
		for(unsigned int i = 0; i < Shader::defaultShaders.size(); i++)
		{
			glUseProgram(Shader::defaultShaders[i].ID);
			GLuint aspectRatioLocation = glGetUniformLocation(Shader::defaultShaders[i].ID, "aspectRatio");
			glUniform1f(aspectRatioLocation, aspectRatio);
		}
	}
}
