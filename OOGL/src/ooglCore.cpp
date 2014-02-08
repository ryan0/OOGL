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



	void setAspectRatio(Vec2u newRatio)
	{
		Shader::aspectRatio = newRatio;
		glUniform1f(Shader::aspectLocation, (float)Shader::aspectRatio.x / (float)Shader::aspectRatio.y);
	}


	void setView(Vec2f newView)
	{
		Shader::view = newView;
		glUniform2f(Shader::viewLocation, Shader::view.x, Shader::view.y);
	}
}
