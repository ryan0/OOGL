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
		void viewSetUp();
		void destroyShader();
		void genRectangleVA();
		void destroyRectangleVA();
	}

	bool ooglInit()
	{
		glewExperimental = GL_TRUE; 
		if(glewInit() == GLEW_OK)
		{
			CorePrivate::genShader();
			CorePrivate::viewSetUp();
			CorePrivate::genRectangleVA();
			return true;
		}
		else return false;
	}

	void ooglTerminate()
	{
		CorePrivate::destroyShader();
		CorePrivate::destroyRectangleVA();
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

	GLfloat clampf(GLfloat f, GLfloat min, GLfloat max)
	{
		if(f < min) f = min;
		else if(f > max) f = max;
		return f;
	}

	Vec2f clampVec2f(Vec2f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
		return vec;
	}

	Vec3f clampVec3f(Vec3f vec, GLfloat min, GLfloat max)
	{
		clampf(vec.x, min, max);
		clampf(vec.y, min, max);
		clampf(vec.z, min, max);
		return vec;
	}
}
