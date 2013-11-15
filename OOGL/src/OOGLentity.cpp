#include <OOGL/OOGLentity.hpp>

namespace oogl
{	
	Entity::Entity(const Entity& newEntity)
		: model(newEntity.model), texture(newEntity.texture), shader(newEntity.shader)
	{
		uniforms = newEntity.uniforms;
		model.genVertexArray(ID, bufferID);
	}


	Entity::Entity(const Model& inModel, const Texture& inTex, shaderType newShader)
		: model(inModel), texture(inTex), shader(newShader)
	{
		uniforms.scale = Vec2(1, 1);
		model.genVertexArray(ID, bufferID);
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		glDeleteBuffers(1, &bufferID);
		glDeleteVertexArrays(1, &ID);

		texture = entity.texture;
		model = entity.model;
		shader = entity.shader;
		uniforms = entity.uniforms;

		model.genVertexArray(ID, bufferID);

		return *this;
	}


	Entity::~Entity()
	{
		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
	}


	void Entity::swapTexture(const Texture& newTex)
	{
		texture = newTex;
	}


	void Entity::setShader(shaderType newShader)
	{
		shader = Shader(newShader);
	}


	void Entity::setPosition(const Vec2& newPosition)
	{
		uniforms.diplacement = newPosition;
	}


	Vec2 Entity::getPosition()
	{
		return uniforms.diplacement;
	}


	void Entity::translate(const Vec2& displacement)
	{
		uniforms.diplacement += displacement;
	}


	void Entity::scale(const Vec2& newScale)
	{
		uniforms.scale *= newScale;
	}


	void Entity::draw()
	{
			glBindVertexArray(ID);
			shader.bind(uniforms);
			texture.bind();

			glDrawArrays(GL_TRIANGLES, 0, model.getDataSize());
	}
}