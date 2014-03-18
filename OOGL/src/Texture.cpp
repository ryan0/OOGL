#include <SOIL/SOIL.h>
#include <OOGL/Core.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/Shader.hpp>

namespace gl
{
	struct Texture::TextureHandle
	{
		GLuint ID;
		TextureHandle(GLuint id) : ID(id) {}
		~TextureHandle() { if(ID != 0)  glDeleteTextures(1, &ID); }

		void bind() const { glBindTexture(GL_TEXTURE_2D, ID); }
		static std::shared_ptr<TextureHandle> loadPNG(std::string imageLocation)
		{
			GLuint tex;
			glGenTextures( 1, &tex);
			glBindTexture(GL_TEXTURE_2D, tex);

			int width, height;
			unsigned char* image = SOIL_load_image( imageLocation.c_str(), &width, &height, 0, SOIL_LOAD_RGBA );
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
			SOIL_free_image_data( image );

			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
			glGenerateMipmap(GL_TEXTURE_2D);

			return std::shared_ptr<TextureHandle>(new TextureHandle(tex));
		}
	};

	Texture::Texture() {}
	Texture::Texture(const std::string& file) : alpha(0), texHandle(TextureHandle::loadPNG(file)) {}

	void Texture::bind() const
	{
		glUniform4f(Shader::getColorLocation(), color.r(), color.g(), color.b(), alpha);
		if(texHandle) texHandle->bind();
	}
	void Texture::destroy() {texHandle = NULL;}


	void Texture::setColor(const Vec3f& newColor)
	{
		color = newColor;
		clampf(color.r(), -1, 1);
		clampf(color.g(), -1, 1);
		clampf(color.b(), -1, 1);
	}
	Vec3f Texture::getColor() const {return color;}

	void Texture::setAlpha(GLfloat A)
	{
		alpha = A;
		clampf(alpha, -1, 1);
	}
	GLfloat Texture::getAlpha() const {return alpha;}
}