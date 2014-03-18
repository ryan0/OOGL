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

	Animation::Animation(const VertexArray& va, const std::vector<Texture>& textures, int milliseconds)
		: VertexArray(va), images(textures), state(paused), millisecPerFrame(milliseconds / textures.size()),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}

	Animation::Animation(const VertexArray& va, const std::string& folder, int texN, int milliseconds)
		: VertexArray(va), images(loadImages(folder, texN)), state(paused), millisecPerFrame(milliseconds / texN),
		millisecLeft(milliseconds), previousTime(0), currentImage(0) {}


	Animation::runState Animation::getState() const {return state;}
	void Animation::pause() const {state = paused;}
	void Animation::run() const   {state = running; previousTime = getTime();}
	void Animation::play() const  {state = playing; previousTime = getTime();}
	void Animation::reset() const {currentImage = 0; millisecLeft = millisecPerFrame;}

	void Animation::draw() const
	{
		update();
		bind();
		glDrawArrays(GL_TRIANGLES, 0, getDataSize());
	}
	void Animation::bind() const {VertexArray::bind(); images[currentImage].bind();}
	void Animation::destroy()	  {VertexArray::destroy(); for(auto& i : images) i.destroy();}


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