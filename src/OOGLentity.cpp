#include "OOGLentity.h"

namespace oogl
{
	std::vector<Entity*> Entity::allEntities;

	
	Entity::Entity() 
	{
		allEntities.push_back(this);
	}


	Entity::Entity(const Model& inModel, const Texture& inTex, ShaderType shaderType)
		: model(inModel), texture(inTex), shader(shaderType), visibility(true)
	{
		uniformData.scale = Vec2(1, 1);

		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);

		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER,bufferID);
		glBufferData(GL_ARRAY_BUFFER, model.data.size() * sizeof(GLfloat), model.data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*) (sizeof(GLfloat) * 2) );

		allEntities.push_back(this);
	}


	Entity& Entity::operator=(const Entity& entity)
	{
		glDeleteBuffers(1, &bufferID);
		glDeleteVertexArrays(1, &ID);

		texture = entity.texture;
		model = entity.model;
		shader = entity.shader;
		uniformData = entity.uniformData;
		visibility = entity.visibility;

		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);

		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER,bufferID);
		glBufferData(GL_ARRAY_BUFFER, model.data.size() * sizeof(GLfloat), model.data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*) (sizeof(GLfloat) * 2) );

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


	void Entity::setShader(ShaderType newShader)
	{
		shader = Shader(newShader);
	}


	void Entity::setPosition(const Vec2& newPosition)
	{
		uniformData.diplacement = newPosition;
	}


	Vec2 Entity::getPosition()
	{
		return uniformData.diplacement;
	}


	void Entity::translate(const Vec2& displacement)
	{
		uniformData.diplacement += displacement;
	}


	void Entity::scale(const Vec2& newScale)
	{
		uniformData.scale *= newScale;
	}


	void Entity::draw()
	{
		if(visibility == true)
		{
			glBindVertexArray(ID);
			shader.bind(uniformData);
			texture.bind();

			glDrawArrays(GL_TRIANGLES, 0, model.data.size());
		}
	}


	void Entity::drawAll()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < allEntities.size(); i++)
		{
			allEntities[i]->draw();
		}
	}


	Entity::~Entity()
	{
		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
		allEntities.erase(std::find(allEntities.begin(), allEntities.end(), this));
	}
}