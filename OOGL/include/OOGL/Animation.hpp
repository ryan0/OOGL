#ifndef OOGLANIMATION_HPP
#define OOGLANIMATION_HPP

#include "Entity.hpp"
#include <string>
#include <vector>

namespace gl
{
	class Texture;
	class VertexArray;

	class Animation : public Entity
	{
	public:
		enum runState
		{
			running,
			playing,
			paused
		};


		Animation();
		Animation(const Animation&);
		Animation(const VertexArray&, const std::vector<Texture>&, int);
		Animation(const Rectangle&, const std::vector<Texture>&, int);
		Animation(const VertexArray&, const std::string&, int, int);
		Animation(const Rectangle&, const std::string&, int, int);

		Animation& operator=(const Animation&);

		void run();
		void play();
		void pause();
		void reset();
		runState getState() const;

		void draw();

	private:
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