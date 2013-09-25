#include "ooglCore.h"
#include "OOGLentity.h"
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
	
		if(Shader::setUpShaders() == false)
			setupSuccess = false;
	
		return setupSuccess;
	}


	void ooglEnd()
	{
		
	}


	void update()
	{
	
	}
}
