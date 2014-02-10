#include <OOGL/ooglCore.hpp>
#include <OOGL/Shader.hpp>
#include <OOGL/Rectangle.hpp>


namespace gl
{
	bool ooglInit()
	{
		glewExperimental = GL_TRUE; 
		if(glewInit() == GLEW_OK)
		{
			Shader::genShader();
			Rectangle::genRectangle();
			return true;
		}
		else
			return false;
	}


	void ooglTerminate()
	{
		
	}


	void clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
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
