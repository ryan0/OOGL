//////////////////////////////////////
//           Shader                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLSHADER_HPP
#define OOGLSHADER_HPP

#include "OOGLvec2.hpp"
#include "../GLEW/glew.h"
#include <vector>


namespace oogl
{	
	enum shaderType
	{
		//Used as indices for Shader class's defaultShaders vector
		NORMAL = 0,
	};


	struct uniformData
	{
		Vec2 scale;
		Vec2 diplacement;
		float rotation;
	};


	class Shader
	{
		friend bool ooglInit();
		friend void setAspectRatio(float, float);

	public:
		Shader();
		Shader(shaderType);

		Shader& operator=(const Shader&);

		void bind(const uniformData&);

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