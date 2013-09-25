#ifndef OOGLSHADER_H
#define OOGLSHADER_H

#include "OOGLvec2.h"
#include <GLEW\glew.h>
#include <vector>


namespace oogl
{	
	enum ShaderType
	{
		//Used as indices for Shader class's defaultShaders vector
		NORMAL = 0,
	};


	struct UniformData
	{
		Vec2 diplacement;
	};


	class Shader
	{
	public:
		Shader();
		Shader(ShaderType);
		void bind(UniformData);

		~Shader();

	private:
		GLuint ID;
		GLuint displacementLocation;

		static bool setUpShaders();
		static bool defaultShadersCreated;
		static std::vector<Shader> defaultShaders;

		Shader& operator=(const Shader&);
		Shader(const char*, const char*);
	};
}
#endif