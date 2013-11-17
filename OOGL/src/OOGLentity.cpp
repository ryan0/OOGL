#include <OOGL/OOGLentity.hpp>

namespace oogl
{	
	Entity::Entity(const Entity& newEntity)
		: model(newEntity.model), texture(newEntity.texture), shader(newEntity.shader)
	{
		model.genVertexArray(ID, bufferID);
	}


	Entity::Entity(const Model& inModel, const Texture& inTex)
		: model(inModel), texture(inTex)
	{
		model.genVertexArray(ID, bufferID);
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		glDeleteBuffers(1, &bufferID);
		glDeleteVertexArrays(1, &ID);

		texture = entity.texture;
		model = entity.model;
		shader = entity.shader;

		model.genVertexArray(ID, bufferID);

		return *this;
	}


	Entity::~Entity()
	{
		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
	}


	void Entity::setAspectRatio(const Vec2<unsigned int>& newRatio)
	{
		Shader::setAspectRatio(newRatio); 
	}


	void Entity::swapTexture(const Texture& newTex)
	{
		texture = newTex;
	}


	void Entity::setPosition(const Vec2<GLfloat>& newPosition)
	{
		shader.uniforms.diplacement = newPosition;
	}


	Vec2<GLfloat> Entity::getPosition()
	{
		return shader.uniforms.diplacement;
	}


	void Entity::translate(const Vec2<GLfloat>& displacement)
	{
		shader.uniforms.diplacement += displacement;
	}


	void Entity::scale(const Vec2<GLfloat>& newScale)
	{
		shader.uniforms.scale *= newScale;
	}


	void Entity::draw()
	{
		glBindVertexArray(ID);
		shader.bind();
		texture.bind();

		glDrawArrays(GL_TRIANGLES, 0, model.getDataSize());
	}
}