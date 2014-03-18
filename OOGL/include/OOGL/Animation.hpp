#ifndef OOGLANIMATION_HPP
#define OOGLANIMATION_HPP

#include "Drawable.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include <string>
#include <vector>

namespace gl
{
	class Animation : public Drawable, public VertexArray
	{
	public: 
		Animation();
		Animation(const VertexArray& va, const std::vector<Texture>& textures, int milliseconds);
		Animation(const VertexArray& va, const std::string& folder, int texN, int milliseconds);

		void draw() const;
		void bind() const;
		void destroy();

		enum runState {running, playing, paused};
		runState getState() const;
		void pause() const;
		void run() const;
		void play() const;
		void reset() const;

	private:
		std::vector<Texture> images;
		int millisecPerFrame;
		mutable runState state;
		mutable int millisecLeft;
		mutable int previousTime;
		mutable int currentImage;

		void update() const;
	};
}
#endif