#include <OOGL\Drawable.hpp>
#include <OOGL\Shader.hpp>
#include <OOGL\Core.hpp>

namespace gl
{
	Drawable::Drawable() : size(1), alpha(0) {}
	Drawable::Drawable(const Shape& shape) : 
		position(shape.position), size(shape.size), alpha(0) {}

	void Drawable::draw() const
	{
		glUniform2f(Shader::getPositionLocation(), position.x, position.y);
		glUniform2f(Shader::getScaleLocation(), size.x, size.y);
		glUniform4f(Shader::getColorLocation(), color.r(), color.g(), color.b(), alpha);
	}

	Vec2f Drawable::getPosition() const			  {return position;}
	void Drawable::setPosition(const Vec2f& vec)  {position = vec;}
	void Drawable::translate(const Vec2f& vec)    {position += vec;}
	Vec2f Drawable::getSize() const			      {return size;}
	void Drawable::setSize(const Vec2f& vec)	  {size = vec;}
	void Drawable::scale(const Vec2f& vec)        {size *= vec;}

	void Drawable::setColor(const Vec3f& newColor)  {color = clampVec3f(newColor, -1, 1);}
	Vec3f Drawable::getColor() const				{return color;}
	void Drawable::setAlpha(GLfloat A)				{alpha = clampf(A, -1, 1);}
	GLfloat Drawable::getAlpha() const				{return alpha;}
}