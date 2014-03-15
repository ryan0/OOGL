#include <OOGL/Animation.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/Core.hpp>
#include <string>

namespace gl
{
	namespace
	{
		std::vector<gl::Texture> loadImages(const std::string& folder, int texNumber)
		{
			std::vector<gl::Texture> images;
			for(int i = 1; i <= texNumber; i++)
				images.push_back(gl::Texture(folder + "/" + std::to_string(i) + ".png"));
			return images;
		}
	}

	Animation::Animation(){}

	Animation::Animation(const VertexArray& va, const std::vector<Texture>& textures, int milliseconds)
		: VertexArray(va), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		currentImage(0), previousTime(0), millisecLeft(milliseconds) {}

	Animation::Animation(const VertexArray& va, const std::string& folder, int texN, int milliseconds)
		: VertexArray(va), images(loadImages(folder, texN)), state(paused), millisecPerFrame(milliseconds / texN),
		currentImage(0), previousTime(0), millisecLeft(milliseconds) {}


	void Animation::run() const
	{
			state = running;
			previousTime = getTime();
	}

	void Animation::play() const
	{
			state = playing;
			previousTime = getTime();
	}

	void Animation::pause() const
	{
			state = paused;
	}

	void Animation::reset() const
	{
		currentImage = 0;
		millisecLeft = millisecPerFrame;
		
		if(state == playing)
			state = paused;
	}

	Animation::runState Animation::getState() const
	{
		return state;
	}

	void Animation::update(int millisecElapsed) const
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

				if(currentImage >= (int)images.size())
					reset();
			}
		}
	}

	void Animation::draw() const
	{
		int currentTime = getTime();
		if(currentTime < previousTime) 
			previousTime = 0;

		update(currentTime - previousTime);
		previousTime = currentTime;

		bind();
		images[currentImage].bind();
		glDrawArrays(GL_TRIANGLES, 0, getDataSize());
	}
}