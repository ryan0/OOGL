#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

namespace gl
{
	class Drawable
	{
	public:
		virtual void draw() const = 0;
		virtual ~Drawable() {}
	};
}
#endif