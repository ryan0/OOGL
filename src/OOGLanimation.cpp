#include "OOGLanimation.h"

namespace oogl
{
	Animation::Animation(Entity& inEntity, std::vector<Texture>& textures, float milliseconds)
		: entity(inEntity), images(textures), millisecondsPerFrame(milliseconds)
	{

	}


	Animation& Animation::operator=(const Animation& newAnimation)
	{

		return *this;
	}

	
	void Animation::run()
	{

	}


	void Animation::play()
	{

	}


	void Animation::pause()
	{

	}


	void Animation::stop()
	{

	}
}