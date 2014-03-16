#include <OOGL/Core.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/Shader.hpp>
#include <Windows.h>

namespace gl
{
	namespace CorePrivate
	{
		void genShader();
		void destroyShader();
		void genDefaultVA();
		void destroyDefaultVA();
	}

	bool ooglInit()
	{
		glewExperimental = GL_TRUE; 
		if(glewInit() == GLEW_OK)
		{
			CorePrivate::genShader();
			CorePrivate::genDefaultVA();
			return true;
		}
		else return false;
	}

	void ooglTerminate()
	{
		CorePrivate::destroyShader();
		CorePrivate::destroyDefaultVA();
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
