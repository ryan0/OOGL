#include <OOGL/Sprite.hpp>

namespace gl
{
	Sprite::Sprite() {}

	Sprite::Sprite(const Shape& shape, const Texture& inTex) 
		: Drawable(shape), va(shape.getVA()), tex(inTex) {}

	Sprite::Sprite(const VertexArray& inVA, const Texture& inTex) 
		: va(inVA), tex(inTex) {}


	void Sprite::draw() const  
	{
		va.bind(); 
		tex.bind();
		Drawable::draw();
		glDrawArrays(GL_TRIANGLES, 0, va.getDataSize());
	}
}