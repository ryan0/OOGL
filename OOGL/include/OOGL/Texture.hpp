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
		void loadPNG(std::string);

		void setColor(const Vec3f&);
		Vec3f getColor() const;
		void setAlpha(GLfloat);
		GLfloat getAlpha() const;

		virtual void bind() const;
		virtual void destroy();

	private:
		struct TextureHandle
		{
			GLuint ID;
			TextureHandle(GLuint id) : ID(id) {}
			~TextureHandle() { if(ID != 0)  glDeleteTextures(1, &ID); }
		};

		Vec3f color;
		float alpha;
		std::shared_ptr<TextureHandle> tHandle;
	};
}

#endif