#include <OOGL/Entity.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/Rectangle.hpp>
#include <OOGL/Shader.hpp>
#include <OOGL/Texture.hpp>


namespace oogl
{	
	Entity::Entity() {}

	Entity::Entity(const Entity& newEntity)
	{
		vertexArray = newEntity.vertexArray;
		texture = newEntity.texture;
	}

	Entity::Entity(const VertexArray& inVA, const Texture& inTex)
	{
		vertexArray = &inVA;
		texture = &inTex;
	}

	Entity::Entity(const Rectangle& rectangle, const Texture& inTex)
		: uniforms(rectangle.position, rectangle.scale)
	{
		vertexArray = &rectangle.getVertexArray();
		texture = &inTex;
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		if(this != &entity)
		{
			texture = entity.texture;
			vertexArray = entity.vertexArray;
			uniforms = entity.uniforms;
		}

		return *this;
	}


	void Entity::setPosition(const Vec2<GLfloat>& newPosition)
	{
		uniforms.position = newPosition;
	}
	void Entity::translate(const Vec2<GLfloat>& displacement)
	{
		uniforms.position += displacement;
	}
	const Vec2<GLfloat>& Entity::getPosition()
	{
		return uniforms.position;
	}


	void Entity::setScale(const Vec2<GLfloat>& newScale)
	{
		uniforms.scale = newScale;
	}
	void Entity::scale(const Vec2<GLfloat>& newScale)
	{
		uniforms.scale *= newScale;
	}
	const Vec2<GLfloat>& Entity::getScale()
	{
		return uniforms.scale;
	}


	void Entity::setTexture(const Texture& newTex)
	{
		texture = &newTex;
	}


	void Entity::draw()
	{
		Shader::bind(uniforms);
		vertexArray->bind();
		texture->bind();

		glDrawArrays(GL_TRIANGLES, 0, vertexArray->getDataSize());
	}
}