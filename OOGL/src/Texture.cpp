#include <OOGL/Texture.hpp>
#include <SOIL/SOIL.h>

namespace gl
{
	Texture::Texture() {}

	Texture::Texture(std::string file)	 
	{
		loadPNG(file);
	}

	Texture::Texture(const Texture& texture)
	{
		glHandle = texture.glHandle;
	}


	Texture& Texture::operator=(const Texture& texture)
	{
		glHandle = texture.glHandle;
		return *this;
	}


	void Texture::bind() const
	{
		if(glHandle) glBindTexture(GL_TEXTURE_2D, glHandle->ID);
		else         glBindTexture(GL_TEXTURE_2D, 0);
	}


	void Texture::setNull()
	{
		glHandle = NULL;
	}


	void Texture::loadPNG(std::string imageLocation)
	{
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

		glHandle.reset(new texHandle(id));
	}
}