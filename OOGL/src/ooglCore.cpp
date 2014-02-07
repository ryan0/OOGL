#include <OOGL/ooglCore.hpp>
#include <OOGL/Shader.hpp>


namespace oogl
{
	bool ooglInit()
	{
		glewExperimental = GL_TRUE; 
		if(glewInit() == GLEW_OK)
		{
			Shader::genShader();
			return true;
		}
		else
			return false;
	}


	void ooglTerminate()
	{
		
	}



	void setAspectRatio(int width, int height)
	{
		Shader::aspectRatio = Vec2<unsigned int>(width, height);
		glUniform1f(Shader::aspectLocation, (float)Shader::aspectRatio.x / (float)Shader::aspectRatio.y);
	}


	void setView(GLfloat x, GLfloat y)
	{
		Shader::view = Vec2<GLfloat>(x, y);
		glUniform2f(Shader::viewLocation, Shader::view.x, Shader::view.y);
	}
}
