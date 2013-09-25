#ifndef OOGLSHADER_H
#define OOGLSHADER_H

#include "OOGLvec2.h"
#include <GLEW\glew.h>
#include <vector>


namespace oogl
{	
	class Shader
	{
	public:
		Shader();
		Shader(int);
		static bool setUpShaders();

		Shader& operator=(const Shader&);

		void bind(Vec2);

		~Shader();

	private:
		GLuint ID;
		GLuint displacementLocation;

		Shader(const char*, const char*);
		static std::vector<Shader> defaultShaders;
	};
}
#endif