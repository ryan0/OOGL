#include <OOGL/Entity.hpp>
#include <OOGL/ooglCore.hpp>


namespace gl
{	
	Entity::Entity() {}

	Entity::Entity(const VertexArray& inVA, const Texture& inTex)
		: VertexArray(inVA), Texture(inTex) {}

	Entity::Entity(const Rectangle& rectangle, const Texture& inTex)
		: VertexArray(rectangle), Texture(inTex) {}

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