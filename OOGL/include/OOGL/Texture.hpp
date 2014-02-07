//////////////////////////////////////
//           Texture                //
//////////////////////////////////////
/*

*/

#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include <string>

namespace oogl
{
	class Texture
	{
	public:
		Texture();
		Texture(const Texture&);
		Texture(std::string);

		Texture& operator=(const Texture&);

		void bind();

	private:
		GLuint ID;
	};
}
#endif