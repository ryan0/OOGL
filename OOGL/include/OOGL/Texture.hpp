#ifndef OOGLTEXTURE_HPP
#define OOGLTEXTURE_HPP

#include "../GLEW/glew.h"
#include "OpenglObject.hpp"
#include "Vec3.hpp"
#include <memory>

namespace gl
{
	class Texture : OpenglObject
	{
	public:
		Texture();
		Texture(const std::string&);
		virtual void bind() const;
		virtual void destroy();

	private:
		struct TextureHandle;
		std::shared_ptr<const TextureHandle> texHandle;
	};
}

#endif