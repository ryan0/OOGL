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
		Sprite() {}
		Sprite(const VertexArray& inVA, const Texture& inTex) : VertexArray(inVA), Texture(inTex) {}

		void bind() const  {VertexArray::bind(); Texture::bind();}
		void destroy()	   {VertexArray::destroy(); Texture::destroy();}
		void draw() const  {bind(); glDrawArrays(GL_TRIANGLES, 0, getDataSize());}
	};
}
#endif