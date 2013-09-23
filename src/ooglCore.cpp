#include <GLEW\glew.h>
#include <iostream>
#include "ooglCore.h"
#include "OOGLshader.h"


namespace oogl
{
	bool start()
	{
		bool setupSuccess = true;


		glewExperimental = GL_TRUE; 
		if(glewInit() != GLEW_OK)
			setupSuccess = false;
	
		if(Shader::setUpShaders() == false)
			setupSuccess = false;
	
		return setupSuccess;
	}


	void end()
	{
	
	}


	void update()
	{
	
	}
}
