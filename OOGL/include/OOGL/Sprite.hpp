#ifndef OOGLSPRITE_HPP
#define OOGLSPRITE_HPP

#include "Drawable.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include <vector>

namespace gl
{
	class Sprite : public Drawable, virtual public VertexArray, virtual public Texture
	{
	public:
		Sprite();
		Sprite(const VertexArray& inVA, const Texture& inTex);

		void bind() const;
		void destroy();
		void draw() const;
	};
}
#endif