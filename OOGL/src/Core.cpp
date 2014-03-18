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
		return	int(time.wMilliseconds) + int(time.wSecond * 1000);
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

	void clampVec2(Vec2f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
	}

	void clampVec3(Vec3f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
		clampf(vec.z, min, max);
	}
}
