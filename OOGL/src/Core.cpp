#include <OOGL/Core.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/Shader.hpp>
#include <Windows.h>


namespace gl
{
	bool ooglInit()
	{
		glewExperimental = GL_TRUE; 
		if(glewInit() == GLEW_OK)
		{
			Shader::genShader();
			VertexArray::genRectangleVA();
			return true;
		}
		else return false;
	}

	void ooglTerminate()
	{
		Shader::destroyShader();
		VertexArray::destroyRectangleVA();
	}

	void clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void clampf(GLfloat& f, GLfloat min, GLfloat max)
	{
		if(f < min) f = min;
		else if(f > max) f = max;
	}

	int getTime()
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return	int(time.wMilliseconds) +
				int(time.wSecond) * 1000 +
				int(time.wMinute) * 60 * 1000;
	}
}
