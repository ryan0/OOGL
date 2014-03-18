#include <OOGL/Sprite.hpp>

namespace gl
{
	Sprite::Sprite() {}
	Sprite::Sprite(const VertexArray& inVA, const Texture& inTex) 
		: VertexArray(inVA), Texture(inTex) {}

	void Sprite::bind() const  
	{
		VertexArray::bind();
		Texture::bind();
	}

	void Sprite::destroy()	  
	{
		VertexArray::destroy();
		Texture::destroy();
	}

	void Sprite::draw() const  
	{
		bind(); 
		glDrawArrays(GL_TRIANGLES, 0, getDataSize());
	}
}