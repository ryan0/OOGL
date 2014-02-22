#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include <string>
#include <memory>

namespace gl
{
	class Texture
	{
	public:
		Texture();
		Texture(std::string);
		Texture(const Texture&);

		Texture& operator=(const Texture&);

		void bind() const;
		void setNull();
		void loadPNG(std::string);

	private:
		struct texHandle
		{
			GLuint ID;

			texHandle(GLuint id) : ID(id) {}

			~texHandle()
			{
				if(ID != 0)  glDeleteTextures(1, &ID);
			}
		};

		std::shared_ptr<const texHandle> glHandle;
	};
}

#endif