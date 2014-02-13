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
		Animation();
		Animation(const Animation&);
		Animation(const VertexArray&, const std::vector<Texture>&, int);
		Animation(const Rectangle&, const std::vector<Texture>&, int);

		Animation& operator=(const Animation&);

		void run();
		void play();
		void pause();
		void reset();
		bool isPaused();

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
		void loadImages();
	};
}

#endif