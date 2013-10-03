#include "OOGLanimation.h"
#include "ooglTime.h"

namespace oogl
{
	std::vector<Animation*> Animation::allAnimations;

	Animation::Animation()
	{
		allAnimations.push_back(this);
	}


	Animation::Animation(const Animation& animation)
		: entity(animation.entity), images(animation.images), millisecondsPerFrame(animation.millisecondsPerFrame),
		state(paused), currentImage(0)
	{
		allAnimations.push_back(this);
	}

	Animation::Animation(Entity& inEntity, std::vector<Texture>& textures, float milliseconds)
		: entity(inEntity), images(textures), millisecondsPerFrame(milliseconds), state(paused), currentImage(0)
	{
		allAnimations.push_back(this);
	}


	Animation::~Animation()
	{
		allAnimations.erase(std::find(allAnimations.begin(), allAnimations.end(), this));
	}


	Animation& Animation::operator=(const Animation& newAnimation)
	{
		entity = newAnimation.entity;
		images = newAnimation.images;
		millisecondsPerFrame = newAnimation.millisecondsPerFrame;
		state = paused;
		currentImage = 0;
		return *this;
	}

	
	void Animation::run()
	{
		if(state != running)
		{
			state = running;
		}
	}


	void Animation::play()
	{
		if(state != playing)
		{
			reset();
			state = playing;
		}
	}


	void Animation::pause()
	{
		if(state != paused)
		{
			state = paused;
		}
	}


	void Animation::reset()
	{
		currentImage = 0;
	}


	void Animation::update(float time)
	{
		float deltaTime = time - previousTime;

		if(deltaTime >= millisecondsPerFrame)
		{
			previousTime = time;

			if(state == running)
			{
				currentImage++;

				if(currentImage >= images.size()) 
					currentImage = 0;

				entity.swapTexture(images[currentImage]);
			}
			else if(state == playing)
			{
				currentImage++;

				if(currentImage >= images.size()) 
				{
					currentImage = 0;
					state = paused;
				}
				entity.swapTexture(images[currentImage]);
			}
		}
	}


	void Animation::updateAnimations()
	{
		float currentTime = getTime();

		for(int i = 0; i < allAnimations.size(); i++)
			allAnimations[i]->update(currentTime);
	}
}