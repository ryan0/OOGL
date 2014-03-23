#ifndef OOGLSPRITE_HPP
#define OOGLSPRITE_HPP

#include "Drawable.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include <vector>

namespace gl
{
	class Sprite : public Drawable
	{
	public:
		Sprite();
		Sprite(const Shape& shape, const Texture& inTex);
		Sprite(const VertexArray& inVA, const Texture& inTex);

		virtual void draw() const;

	private:
		VertexArray va;
		Texture tex;
	};
}
#endif