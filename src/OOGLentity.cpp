#include "OOGLentity.h"

namespace oogl
{
	std::vector<Entity*> Entity::allEntities;

	
	Entity::Entity() 
	{
		allEntities.push_back(this);
	}


	Entity::Entity(const Entity& newEntity)
	{
		*this = newEntity;
		allEntities.push_back(this);
	}


	Entity::Entity(const Model& inModel, const Texture& inTex, shaderType newShader)
		: model(inModel), texture(inTex), shader(newShader), visibility(true)
	{
		uniforms.scale = Vec2(1, 1);

		model.genVertexArray(ID, bufferID);

		allEntities.push_back(this);
	}


	Entity::~Entity()
	{
		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
		allEntities.erase(std::find(allEntities.begin(), allEntities.end(), this));
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		glDeleteBuffers(1, &bufferID);
		glDeleteVertexArrays(1, &ID);

		texture = entity.texture;
		model = entity.model;
		shader = entity.shader;
		uniforms = entity.uniforms;
		visibility = entity.visibility;

		model.genVertexArray(ID, bufferID);

		return *this;
	}


	void Entity::visible(bool newVisibility)
	{
		visibility = newVisibility;
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
		if(visibility == true)
		{
			glBindVertexArray(ID);
			shader.bind(uniforms);
			texture.bind();

			glDrawArrays(GL_TRIANGLES, 0, model.getDataSize());
		}
	}


	void Entity::drawAll()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < allEntities.size(); i++)
			allEntities[i]->draw();
	}
}