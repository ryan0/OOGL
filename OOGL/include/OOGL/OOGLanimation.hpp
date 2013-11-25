//////////////////////////////////////
//           Animation              //
//////////////////////////////////////
/*

*/

#ifndef OOGLANIMATION_HPP
#define OOGLANIMATION_HPP

#include "OOGLentity.hpp"
#include "OOGLtexture.hpp"
#include "OOGLmodel.hpp"
#include <vector>

namespace oogl
{
	class Animation : public Entity
	{
	public:
		Animation();
		Animation(const Animation&);
		Animation(const Model&, const std::vector<Texture>&, int);

		Animation& operator=(const Animation&);

		void run();
		void play();
		void pause();
		void reset();

		void draw();

	private:
		enum runState
		{
			running,
			playing,
			paused
		};

		int previousTime;
		int millisecPerFrame;
		int millisecLeft;
		int currentImage;

		runState state;
		std::vector<Texture> images;

		void update(int);
	};
}

#endif