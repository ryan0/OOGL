#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include <string>
#include <memory>
#include <iostream>

namespace gl
{
	class Texture
	{
	public:
		Texture();
		Texture(const Texture&);
		Texture(std::string);

		Texture& operator=(const Texture&);

		void bind() const;
		void loadPNG(std::string);
		void setNull();

	private:
		struct texHandle
		{
			GLuint ID;

			texHandle(GLuint id)
				: ID(id) {}

			~texHandle()
			{
				if(ID != 0)
					glDeleteTextures(1, &ID);

				std::cout<<"texHandle deleted\n";
			}
		};

		std::shared_ptr<const texHandle> glHandle;
	};
}

#endif