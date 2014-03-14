#ifndef OOGLANIMATION_HPP
#define OOGLANIMATION_HPP

#include "VertexArray.hpp"
#include "Texture.hpp"
#include <string>
#include <vector>

namespace gl
{
	class Rectangle;

	class Animation : public VertexArray
	{
	public:
		enum runState
		{
			running,
			playing,
			paused
		};

		Animation();
		Animation(const VertexArray&, const std::vector<Texture>&, int);
		Animation(const Rectangle&, const std::vector<Texture>&, int);
		Animation(const VertexArray&, const std::string&, int, int);
		Animation(const Rectangle&, const std::string&, int, int);

		void draw() const;
		runState getState() const;
		void pause() const;
		void play() const;
		void run() const;
		void reset() const;

	private:
		std::vector<Texture> images;
		int millisecPerFrame;

		mutable runState state;
		mutable int currentImage;
		mutable int millisecLeft;
		mutable int previousTime;

		void update(int) const;
	};
}

#endif