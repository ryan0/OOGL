#ifndef OOGLANIMATION_HPP
#define OOGLANIMATION_HPP

#include "VertexArray.hpp"
#include "Texture.hpp"
#include "Core.hpp"
#include <string>
#include <vector>

namespace gl
{
	class Animation : public VertexArray
	{
	public: enum runState {running, playing, paused};
	private:
		std::vector<Texture> images;
		int millisecPerFrame;
		mutable runState state;
		mutable int currentImage;
		mutable int millisecLeft;
		mutable int previousTime;

		static std::vector<gl::Texture> loadImages(const std::string& folder, int texNumber)
		{
			std::vector<gl::Texture> images;
			for(int i = 1; i <= texNumber; i++)
				images.push_back(gl::Texture(folder + "/" + std::to_string(i) + ".png"));
			return images;
		}

		void update(int millisecElapsed) const
		{
			millisecLeft -= millisecElapsed;
			if(millisecLeft <= 0)
			{
				millisecLeft = millisecPerFrame;
				currentImage++;
				if(currentImage >= (int)images.size()) reset();
			}
		}

	public:
		Animation::Animation(){}

		Animation::Animation(const VertexArray& va, const std::vector<Texture>& textures, int milliseconds)
			: VertexArray(va), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
			currentImage(0), previousTime(0), millisecLeft(milliseconds) {}

		Animation::Animation(const VertexArray& va, const std::string& folder, int texN, int milliseconds)
			: VertexArray(va), images(loadImages(folder, texN)), state(paused), millisecPerFrame(milliseconds / texN),
			currentImage(0), previousTime(0), millisecLeft(milliseconds) {}


		runState Animation::getState() const {return state;}
		void pause() const	{state = paused;}
		void run() const	{state = running; previousTime = getTime();}
		void play() const	{state = playing; previousTime = getTime();}
		void reset() const	{currentImage = 0; millisecLeft = millisecPerFrame;}

		void bind() const  {VertexArray::bind(); images[currentImage].bind();}
		void draw() const
		{
			int currentTime = getTime();
			if(currentTime > previousTime) update(currentTime - previousTime);
			previousTime = currentTime;
			bind();
			glDrawArrays(GL_TRIANGLES, 0, getDataSize());
		}
	};
}
#endif