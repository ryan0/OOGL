#include <OOGL/Animation.hpp>
#include <OOGL/Core.hpp>

namespace gl
{
	static std::vector<gl::Texture> loadImages(const std::string& folder, int texNumber)
	{
		std::vector<gl::Texture> images;
		for(int i = 1; i <= texNumber; i++) images.push_back(gl::Texture(folder+"/"+std::to_string(i)+".png"));
		return images;
	}


	Animation::Animation(){}

	Animation::Animation(const Shape& shape, const std::vector<Texture>& textures, int milliseconds)
		: Drawable(shape), va(shape.getVA()), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}

	Animation::Animation(const Shape& shape, const std::string& folder, int texN, int milliseconds)
		: Drawable(shape), va(shape.getVA()), images(loadImages(folder, texN)), state(paused), millisecPerFrame(milliseconds / texN),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}

	Animation::Animation(const VertexArray& inVA, const std::vector<Texture>& textures, int milliseconds)
		: va(inVA), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}

	Animation::Animation(const VertexArray& inVA, const std::string& folder, int texN, int milliseconds)
		: va(inVA), images(loadImages(folder, texN)), state(paused), millisecPerFrame(milliseconds / texN),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}


	Animation::runState Animation::getState() const {return state;}
	void Animation::pause() const {state = paused;}
	void Animation::run() const   {state = running; previousTime = getTime();}
	void Animation::play() const  {state = playing; previousTime = getTime();}
	void Animation::reset() const {currentImage = 0; millisecLeft = millisecPerFrame;}

	void Animation::draw() const
	{
		update();
		va.bind();
		images[currentImage].bind();
		Drawable::draw();
		glDrawArrays(GL_TRIANGLES, 0, va.getDataSize());
	}

	void Animation::update() const
	{
		int time = getTime();
		if(previousTime > time) previousTime = 0;
		else if(time - previousTime > millisecPerFrame)
		{
			currentImage++;
			if(currentImage >= (int)images.size()) reset();
			previousTime = time;
		}
	}

}