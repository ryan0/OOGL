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
		Animation(const VertexArray&, const std::vector<Texture>&, int);
		Animation(const Rectangle&, const std::vector<Texture>&, int);
		Animation(const VertexArray&, const std::string&, int, int);
		Animation(const Rectangle&, const std::string&, int, int);

		virtual void draw();

		runState getState() const;
		void pause();
		void play();
		void run();
		void reset();

	private:
		std::vector<Texture> images;
		runState state;
		int millisecPerFrame;
		int currentImage;
		int millisecLeft;
		int previousTime;

		void update(int);
	};
}

#endif