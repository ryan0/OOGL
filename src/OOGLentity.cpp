#include "OOGLentity.h"

namespace oogl
{
	std::vector<Entity*> Entity::allEntities;

	
	Entity::Entity()
	{

	}


	Entity::Entity(const Model& inModel, const Texture& inTex, ShaderType shaderType)
	{
		shader = Shader::defaultShaders[shaderType];
		texture = inTex;
		model = inModel;
		visible = true;

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

	Entity::~Entity()
	{
		for(int i = 0; i < allEntities.size() ; i++)
			if(this == allEntities[i]) allEntities.erase(allEntities.begin() + i);

		glDeleteVertexArrays(1, &ID);
		glDeleteBuffers(1, &bufferID);
	}


	void Entity::visibility(bool newVisibility)
	{
		visible = newVisibility;
	}


	void Entity::setPosition(const Vec2& newPosition)
	{
		position = newPosition;
	}


	void Entity::translate(const Vec2& displacement)
	{
		position += displacement;
	}


	void Entity::draw()
	{
		if(visible == true)
		{
			glBindVertexArray(ID);
			glUseProgram(shader.ID);
			glBindTexture(GL_TEXTURE_2D, texture.ID);

			glUniform2f(shader.displacementLocation, position.x, position.y);

			glDrawArrays(GL_TRIANGLES, 0, model.data.size());
		}
	}


	void Entity::drawAll()
	{
		for (int i = 0; i < allEntities.size(); i++)
		{
			allEntities[i]->draw();
		}
	}
}