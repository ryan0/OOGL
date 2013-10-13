//////////////////////////////////////
//           Texture                //
//////////////////////////////////////
/*

*/

#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"

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