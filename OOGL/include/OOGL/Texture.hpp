#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include "Vec3.hpp"
#include "OpenglObject.hpp"
#include <string>
#include <memory>

namespace gl
{
	class Texture : OpenglObject
	{
	public:
		Texture();
		Texture(std::string);
		
		virtual void bind() const;

		void setColor(const Vec3f&);
		Vec3f getColor() const;
		void setAlpha(GLfloat);
		GLfloat getAlpha() const;

	private:
		struct TextureHandle : OpenglHandle
		{
			GLuint ID;
			TextureHandle(GLuint id) : ID(id) {}
			virtual void bind() const { glBindTexture(GL_TEXTURE_2D, ID); }
			~TextureHandle() { if(ID != 0)  glDeleteTextures(1, &ID); }
		};


		Vec3f color;
		float alpha;

		void loadPNG(std::string);
	};
}

#endif