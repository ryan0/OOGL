//////////////////////////////////////
//           Animation              //
//////////////////////////////////////
/*

*/

#ifndef OOGLANIMATION_H
#define OOGLANIMATION_H

#include "OOGLentity.h"
#include "OOGLtexture.h"
#include <vector>

namespace oogl
{
	class Animation
	{
	public:

		Animation(Entity&, std::vector<Texture>&, float);

		Animation& operator=(const Animation&);

		void run();
		void play();
		void pause();
		void stop();

		Entity entity;

	private:

		const float millisecondsPerFrame;
		std::vector<Texture> images;
	};
}

#endif