#include "OOGLmodel.h"

namespace oogl
{
	Model::Model()
	{

	}


	Model::Model(const char* filename)
	{

	}


	Model::Model(const Vec2& center, float size)
	{
							  //coordinates and UVs//
					// X //								// Y //
		data.push_back(center.x - size);	data.push_back(center.y - size);
		data.push_back(0);	//U				
		data.push_back(0);	//V

		data.push_back(center.x - size);	data.push_back(center.y + size);
		data.push_back(0);	//U				
		data.push_back(1);	//V

		data.push_back(center.x + size);	data.push_back(center.y + size);
		data.push_back(1);	//U				
		data.push_back(1);	//V

		data.push_back(center.x + size);	data.push_back(center.y + size);
		data.push_back(1);	//U				
		data.push_back(1);	//V

		data.push_back(center.x + size);	data.push_back(center.y - size);
		data.push_back(1);	//U				
		data.push_back(0);	//V

		data.push_back(center.x - size);	data.push_back(center.y - size);
		data.push_back(0);	//U				
		data.push_back(0);	//V
	}


	Model::Model(const std::vector<Vec2>& coordinates, const std::vector<Vec2>& uvs)
	{
		for(int i = 0; i < coordinates.size(); i ++)
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
}