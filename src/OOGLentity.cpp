#include "OOGLentity.h"

namespace oogl
{
	Entity::Entity(const Model& inModel, const Texture& inTex, ShaderType shaderType)
	{
		model = inModel;
		texture = inTex;

		switch(shaderType)
		{
		case NORMAL:
			shader = Shader::defaultShaders[NORMAL];
			break;
		}

		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);

		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER,bufferID);
		glBufferData(GL_ARRAY_BUFFER, model.data.size() * sizeof(GLfloat), &model.data[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*) (sizeof(GLfloat) * 2) );

		allEntities.push_back(*this);
	}


	void Entity::draw()
	{
		glBindVertexArray(ID);
		glUseProgram(shader.ID);
		glBindTexture(GL_TEXTURE_2D, texture.ID);

		glDrawArrays(GL_TRIANGLES, 0, model.data.size());
	}

	void Entity::drawAll()
	{
		for (int i = 0; i < allEntities.size(); i++)
		{
			allEntities[i].draw();
		}
	}
}