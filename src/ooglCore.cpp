#include <GLEW\glew.h>
#include "ooglCore.h"
#include "OOGLshader.h"

namespace oogl
{
	bool start()
	{
		if(!glewInit())
			return false;
	
		if(!Shader::setUpShaders())
			return false;
	
		return true;
	}


	void end()
	{
	
	}


	void update()
	{
	
	}
}
