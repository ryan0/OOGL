#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Shape.hpp"

namespace gl
{
	class Drawable
	{
	public:
		Drawable();
		Drawable(const Shape&);
		virtual ~Drawable() {}

		virtual void draw() const = 0;

		Vec2f getPosition() const;
		void setPosition(const Vec2f&);
		void translate(const Vec2f&);
		Vec2f getSize() const;
		void setSize(const Vec2f&);
		void scale(const Vec2f&);

		void setColor(const Vec3f&);
		Vec3f getColor() const;
		void setAlpha(GLfloat);
		GLfloat getAlpha() const;

	private:
		Vec2f position, size;
		Vec3f color;
		float alpha;
	};
}
#endif