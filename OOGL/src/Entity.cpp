#include <OOGL/Entity.hpp>
#include <OOGL/Shader.hpp>

namespace oogl
{	
	Entity::Entity() 
	{
		shader = new Shader();

	}

	Entity::Entity(const Entity& newEntity)
		: model(newEntity.model), texture(newEntity.texture)
	{
		shader = new Shader(*newEntity.shader);
		model.genVertexArray(ID, bufferID);
	}

	Entity::Entity(const Model& inModel, const Texture& inTex)
		: model(inModel), texture(inTex)
	{
		shader = new Shader();
		model.genVertexArray(ID, bufferID);
	}


	Entity::~Entity()
	{
		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
		delete shader;
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		if(this != &entity)
		{
			glDeleteBuffers(1, &bufferID);
			glDeleteVertexArrays(1, &ID);

			texture = entity.texture;
			model = entity.model;
			*shader = Shader(*entity.shader);

			model.genVertexArray(ID, bufferID);
		}

		return *this;
	}



	void Entity::setPosition(const Vec2<GLfloat>& newPosition)
	{
		shader->uniforms.diplacement = newPosition;
	}
	void Entity::translate(const Vec2<GLfloat>& displacement)
	{
		shader->uniforms.diplacement += displacement;
	}
	const Vec2<GLfloat>& Entity::getPosition()
	{
		return shader->uniforms.diplacement;
	}


	void Entity::setScale(const Vec2<GLfloat>& newScale)
	{
		shader->uniforms.scale = newScale;
	}
	void Entity::scale(const Vec2<GLfloat>& newScale)
	{
		shader->uniforms.scale *= newScale;
	}
	const Vec2<GLfloat>& Entity::getScale()
	{
		return shader->uniforms.scale;
	}


	void Entity::setTexture(const Texture& newTex)
	{
		texture = newTex;
	}

	void Entity::draw()
	{
		glBindVertexArray(ID);
		shader->bind();
		texture.bind();

		glDrawArrays(GL_TRIANGLES, 0, model.getDataSize());
	}
}