#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include "OpenglObject.hpp"
#include "Vec3.hpp"
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
		virtual void destroy();

		void setColor(const Vec3f&);
		Vec3f getColor() const;
		void setAlpha(GLfloat);
		GLfloat getAlpha() const;

	private:
		Vec3f color;
		float alpha;
		struct TextureHandle;
		std::shared_ptr<const TextureHandle> texHandle;
	};
}

#endif