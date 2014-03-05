#include <OOGL/Entity.hpp>


namespace gl
{	
	Entity::Entity() {}

	Entity::Entity(const Entity& entity)
		: uniforms(entity.uniforms), vertexArray(entity.vertexArray), texture(entity.texture) {}

	Entity::Entity(const VertexArray& inVA, const Texture& inTex)
		: vertexArray(inVA), texture(inTex) {}

	Entity::Entity(const Rectangle& rectangle, const Texture& inTex)
		: uniforms(rectangle.position, rectangle.scale), vertexArray(rectangle.getVertexArray()), texture(inTex) {}


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
	const Vec2<GLfloat>& Entity::getPosition() const
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
	const Vec2<GLfloat>& Entity::getScale() const
	{
		return uniforms.scale;
	}


	void Entity::setColor(const Vec3f& color)
	{
		uniforms.color = color;
	}
	const Vec3f& Entity::getColor() const
	{
		return uniforms.color;
	}
	void Entity::setAlpha(GLfloat A)
	{
		uniforms.alpha = A;
	}
	GLfloat Entity::getAlpha() const
	{
		return uniforms.alpha;
	}


	void Entity::setTexture(const Texture& newTex)
	{
		texture = newTex;
	}
	const Texture& Entity::getTexture() const
	{
		return texture;
	};


	void Entity::draw()
	{
		uniforms.bind();
		vertexArray.bind();
		texture.bind();

		glDrawArrays(GL_TRIANGLES, 0, vertexArray.getDataSize());
	}
}