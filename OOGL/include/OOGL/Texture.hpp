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
		Texture(std::string);
		~Texture();

		Texture& operator=(const Texture&);

		void clear();
		void loadPNG(std::string);
		void bind() const;

	private:
		GLuint ID;
		bool isClear;
	};
}

#endif