#include <OOGL\Core.hpp>
#include <OOGL\Shader.hpp>

namespace
{
	GLuint aspectLocation = 0;
	GLuint PositionLocation = 0;
	GLuint colorLocation = 0;
}

namespace gl
{	
	namespace View
	{
		void setAspectRatio(Vec2u newRatio)
		{
				glUniform1f(aspectLocation, (float)newRatio.x / (float)newRatio.y);
		}
		void setPosition(Vec2f newView)
		{
			glUniform2f(PositionLocation, newView.x, newView.y);
		}
		void setColor(Vec3f color)
		{
			glUniform4f(colorLocation, color.r(), color.g(), color.b(), 0);
		}
	}



	namespace CorePrivate
	{
		void viewSetUp()
		{
			aspectLocation = glGetUniformLocation(Shader::getID(), "viewAspect");
			PositionLocation = glGetUniformLocation(Shader::getID(), "viewPosition");
			colorLocation = glGetUniformLocation(Shader::getID(), "viewColor");

			glUniform1f(aspectLocation, 1);
			glUniform2f(PositionLocation, 0, 0);
			glUniform4f(PositionLocation, 0, 0, 0, 0);
		}
	}
}