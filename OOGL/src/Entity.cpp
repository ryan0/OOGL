#include <OOGL/Entity.hpp>


namespace gl
{	
	Entity::Entity() {}

	Entity::Entity(const VertexArray& inVA, const Texture& inTex)
		: VertexArray(inVA), Texture(inTex) {}


	void Entity::destroy()
	{
		VertexArray::destroy();
		Texture::destroy();
	}

	void Entity::bind() const
	{
		VertexArray::bind();
		Texture::bind();
	}

	void Entity::draw() const
	{
		bind();
		glDrawArrays(GL_TRIANGLES, 0, getDataSize());
	}
}