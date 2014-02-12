#include <OOGL/Animation.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/ooglTime.hpp>
#include <string>

namespace gl
{
	Animation::Animation(){}

	Animation::Animation(const Animation& animation)
		: Entity(animation), images(animation.images), millisecLeft(animation.millisecLeft),
		millisecPerFrame(animation.millisecPerFrame), state(paused), currentImage(0) {}


	Animation::Animation(const VertexArray& vertexArray, const std::vector<Texture>& textures, int milliseconds)
		: Entity(vertexArray, textures[0]), images(textures), millisecLeft(milliseconds), state(paused), currentImage(0) 
	{
		millisecPerFrame = milliseconds / images.size();
		millisecLeft = milliseconds;
	}


	Animation::Animation(const Rectangle& rectangle, const std::vector<Texture>& textures, int milliseconds)
		: Entity(rectangle, textures[0]), images(textures), millisecLeft(milliseconds), state(paused), currentImage(0) 
	{
		millisecPerFrame = milliseconds / images.size();
		millisecLeft = milliseconds;
	}


	Animation& Animation::operator=(const Animation& newAnimation)
	{
		Entity::operator=(newAnimation);
		images = newAnimation.images;
		millisecPerFrame = newAnimation.millisecPerFrame;
		millisecLeft = newAnimation.millisecLeft;
		previousTime = previousTime;
		state = newAnimation.state;
		reset();
		return *this;
	}


	void Animation::run()
	{
			state = running;
			previousTime = getTime();
	}


	void Animation::play()
	{
			state = playing;
			previousTime = getTime();
	}


	void Animation::pause()
	{
			state = paused;
	}


	void Animation::reset()
	{
		currentImage = 0;
		setTexture(images[currentImage]);
		millisecLeft = millisecPerFrame;
		
		if(state == playing)
			state = paused;
	}


	bool Animation::isPaused()
	{
		if(state == paused)
			return true;
		else
			return false;
	}


	void Animation::update(int millisecElapsed)
	{
		while(millisecElapsed > 0 && (state == playing || state == running))
		{
			if(millisecElapsed <= millisecLeft)
			{	
				millisecLeft -= millisecElapsed;
				millisecElapsed = 0;
			}
			else if(millisecElapsed > millisecLeft)
			{
				 millisecElapsed -= millisecLeft;
				 millisecLeft = 0;
			}
		
			if(millisecLeft == 0)
			{
				millisecLeft = millisecPerFrame;
				currentImage++;

				if(currentImage < (int)images.size())
					setTexture(images[currentImage]);
				else
					reset();
			}
		}
	}


	void Animation::draw()
	{
		int currentTime = getTime();
		if(currentTime < previousTime) 
			previousTime = 0;

		update(currentTime - previousTime);
		previousTime = currentTime;

		Entity::draw();
	}
}