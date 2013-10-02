#include "ooglCore.h"
#include "OOGLshader.h"
#include <GLEW\glew.h>



namespace oogl
{
	bool ooglInit()
	{
		bool setupSuccess = true;

		glewExperimental = GL_TRUE; 
		if(glewInit() != GLEW_OK)
			setupSuccess = false;
	
		Shader::setUpShaders();

		Shader::aspectRatio(Vec2(1, 1));

		return setupSuccess;
	}


	void ooglTerminate()
	{
		
	}
}
