#ifndef OOGLSPRITE_HPP
#define OOGLSPRITE_HPP

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include "../GLEW/glew.h"
#include <vector>

namespace gl
{
	class Sprite : virtual public VertexArray, virtual public Texture
	{
	public:
		Sprite::Sprite() {}
		Sprite::Sprite(const VertexArray& inVA, const Texture& inTex) : VertexArray(inVA), Texture(inTex) {}

		void Sprite::bind() const  {VertexArray::bind(); Texture::bind();}
		void Sprite::destroy()	   {VertexArray::destroy(); Texture::destroy();}
		void Sprite::draw() const  {bind(); glDrawArrays(GL_TRIANGLES, 0, getDataSize());}
	};
}
#endif