#include <OOGL/Texture.hpp>
#include <SOIL/SOIL.h>

namespace gl
{
	Texture::Texture()
		:isClear(true) {}

	Texture::Texture(std::string imageLocation)
		:isClear(true) 
	{
		loadPNG(imageLocation);
	}


	Texture::~Texture()
	{
		clear();
	}


	Texture& Texture::operator=(const Texture& texture)
	{
		clear();
		ID = texture.ID;
		return *this;
	}


	void Texture::clear()
	{
		if(isClear == false)
		{
			isClear = true;
			glDeleteTextures(1, &ID);
		}
	}


	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, ID);
	}


	void Texture::loadPNG(std::string imageLocation)
	{
		clear();
		GLuint id;

		glGenTextures( 1, &id );
		glBindTexture(GL_TEXTURE_2D, id);

		int width, height;
		unsigned char* image = SOIL_load_image( imageLocation.c_str(), &width, &height, 0, SOIL_LOAD_RGBA );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
		SOIL_free_image_data( image );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

		glGenerateMipmap(GL_TEXTURE_2D);

		isClear = false;
		ID = id;
	}
}