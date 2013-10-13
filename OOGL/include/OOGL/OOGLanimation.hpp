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
#include "OOGLshader.hpp"
#include <vector>

namespace oogl
{
	class Animation
	{
	public:

		Entity entity;

		Animation();
		Animation(const Animation&);
		Animation(const Model&, const std::vector<Texture>&, shaderType, float);
		~Animation();

		Animation& operator=(const Animation&);

		void run();
		void play();
		void pause();

		void reset();

		static void updateAnimations();

	private:

		enum runState
		{
			running,
			playing,
			paused
		};

		unsigned int currentImage;
		runState state;
		float millisecondsPerFrame;
		float previousTime;
		std::vector<Texture> images;
		static std::vector<Animation*> allAnimations;

		void update(float);
	};
}

#endif