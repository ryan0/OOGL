//////////////////////////////////////
//           Texture                //
//////////////////////////////////////
/*

*/

#ifndef OOGLTEXTURE_H
#define OOGLTEXTURE_H

#include <GLEW\glew.h>

namespace oogl
{
	class Texture
	{
	public:
		Texture();
		Texture(const Texture&);
		Texture(const char*);

		Texture& operator=(const Texture&);

		void bind();

	private:
		GLuint ID;
	};
}
#endif