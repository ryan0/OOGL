#ifndef OOGLTEXTURE_H
#define OOGLTEXTURE_H

#include <GLEW\glew.h>

namespace oogl
{
	class Entity;

	class Texture
	{
		friend class Entity; 

	private:
		GLuint ID;

	public:
		Texture();
		Texture(const char*);
		Texture& operator=(const Texture&);
	};
}
#endif