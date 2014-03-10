#include <OOGL/Animation.hpp>
#include <OOGL/Texture.hpp>
#include <OOGL/VertexArray.hpp>
#include <OOGL/ooglCore.hpp>
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

	Animation::Animation(const VertexArray& vertexArray, const std::vector<Texture>& textures, int milliseconds)
		: Entity(vertexArray, textures[0]), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		currentImage(0), previousTime(0), millisecLeft(milliseconds) {}

	Animation::Animation(const Rectangle& rectangle, const std::vector<Texture>& textures, int milliseconds)
		: Entity(rectangle, textures[0]), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		currentImage(0), previousTime(0), millisecLeft(milliseconds) {}

	Animation::Animation(const VertexArray& vertexArray, const std::string& folder, int texN, int milliseconds)
	{   *this = Animation(vertexArray, loadImages(folder, texN), milliseconds); }

	Animation::Animation(const Rectangle& rectangle, const std::string& folder, int texN, int milliseconds)
	{	*this = Animation(rectangle, loadImages(folder, texN), milliseconds); }


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

	Animation::runState Animation::getState() const
	{
		return state;
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