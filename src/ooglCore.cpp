#include "ooglCore.h"
#include <GLEW\glew.h>



namespace oogl
{
	bool ooglInit()
	{
		bool setupSuccess = true;

		glewExperimental = GL_TRUE; 
		if(glewInit() != GLEW_OK)
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
