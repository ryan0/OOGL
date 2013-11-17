#include <OOGL/ooglCore.hpp>
#include <OOGL/OOGLentity.hpp>
#include <GLEW/glew.h>



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


	void ooglTerminate()
	{
		
	}
}
