#include "OOGLmodel.h"
#include <vector>
using namespace std;

namespace oogl
{
	Model::Model(const char* filename)
	{

	}


	Model::Model(const vector<Vec2>& coordinates, const vector<Vec2>& uvs)
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