//////////////////////////////////////
//           Shader                 //
//////////////////////////////////////
/*

*/

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
		Vec2 scale;
		Vec2 diplacement;
		float rotation;
	};


	class Shader
	{
		friend bool ooglInit();

	public:
		Shader();
		Shader(ShaderType);

		Shader& operator=(const Shader&);

		void bind(const UniformData&);

		static void aspectRatio(const Vec2&);

	private:
		GLuint ID;
		GLuint displacementLocation;
		GLuint scaleLocation;

		static void setUpShaders();
		static std::vector<Shader> defaultShaders;

		Shader(const char*, const char*);
	};
}
#endif