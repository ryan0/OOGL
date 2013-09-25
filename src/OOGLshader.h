#ifndef OOGLSHADER_H
#define OOGLSHADER_H

#include <GLEW\glew.h>
#include <vector>


namespace oogl
{	
	class Entity;

	class Shader
	{
		friend class Entity;
		friend bool ooglInit();

	private:
		GLuint ID;
		GLuint displacementLocation;

		static std::vector<Shader> defaultShaders;
		static bool setUpShaders();

		Shader();
		Shader(const char*, const char*);

		Shader& operator=(const Shader&);

	public:
		~Shader();
	};
}
#endif