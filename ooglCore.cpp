#include "ooglCore.h"
#include "GLEW\glew.h"




bool ooglStart()
{
	if(!glewInit())
		return false;
	return true;
}


void ooglEnd()
{

}


void ooglUpdate()
{

}
