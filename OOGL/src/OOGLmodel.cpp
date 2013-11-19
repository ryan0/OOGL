#include <OOGL/OOGLmodel.hpp>

namespace oogl
{
	Model::Model()
		: data() {}


	Model::Model(const Model& model)
		: data(model.data) {}

	Model::Model(const char* filename)
	{

	}


	Model::Model(const Vec2<GLfloat>& center, float size)
	{
							  //coordinates and UVs//
					// X //								// Y //
		data.push_back(center.x - size / 2);	data.push_back(center.y - size / 2);
		data.push_back(0);	//U				
		data.push_back(1);	//V

		data.push_back(center.x - size / 2);	data.push_back(center.y + size / 2);
		data.push_back(0);	//U				
		data.push_back(0);	//V

		data.push_back(center.x + size / 2);	data.push_back(center.y + size / 2);
		data.push_back(1);	//U				
		data.push_back(0);	//V

		data.push_back(center.x + size / 2);	data.push_back(center.y + size / 2);
		data.push_back(1);	//U				
		data.push_back(0);	//V

		data.push_back(center.x + size / 2);	data.push_back(center.y - size / 2);
		data.push_back(1);	//U				
		data.push_back(1);	//V

		data.push_back(center.x - size / 2);	data.push_back(center.y - size / 2);
		data.push_back(0);	//U				
		data.push_back(1);	//V
	}


	Model::Model(const std::vector<Vec2<GLfloat>>& coordinates, const std::vector<Vec2<GLfloat>>& uvs)
	{
		for(unsigned int i = 0; i < coordinates.size(); i ++)
		{
			data.push_back(coordinates[i].x);
			data.push_back(coordinates[i].y);

			if(i >= uvs.size())
			{
				data.push_back(uvs.back().x);
				data.push_back(uvs.back().y);
			}
			else
			{
				data.push_back(uvs[i].x);
				data.push_back(uvs[i].y);
			}
		}
	}


	Model& Model::operator=(const Model& model)
	{
		data = model.data;
		return *this;
	}


	int Model::getDataSize()
	{
		return data.size();
	}

	void Model::genVertexArray(GLuint& arrayId, GLuint& bufferId)
	{
		glGenVertexArrays(1, &arrayId);
		glBindVertexArray(arrayId);

		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER,bufferId);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*) (sizeof(GLfloat) * 2) );
	}
}