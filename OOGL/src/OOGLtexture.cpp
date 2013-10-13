#include <OOGL/OOGLtexture.hpp>
#include <SOIL/SOIL.h>

namespace oogl
{
	Texture::Texture() 
		: ID(0) {}


	Texture::Texture(const Texture& texture)
		: ID(texture.ID) {}


	Texture::Texture(const char* imageLocation)
	{
		glGenTextures( 1, &ID );
		glBindTexture(GL_TEXTURE_2D, ID);

		int width, height;
		unsigned char* image = SOIL_load_image( imageLocation, &width, &height, 0, SOIL_LOAD_RGBA );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
		SOIL_free_image_data( image );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

		glGenerateMipmap(GL_TEXTURE_2D);
	}


	Texture& Texture::operator=(const Texture& texture)
	{
		ID = texture.ID;
		return *this;
	}


	void Texture::bind()
	{
		glBindTexture(GL_TEXTURE_2D, ID);
	}
}