//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "Vec2.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include "Rectangle.hpp"
#include "Uniforms.hpp"
#include "../GLEW/glew.h"
#include <vector>

namespace gl
{
	class Entity
	{
	public:
		Entity();
		Entity(const Entity&);
		Entity(const VertexArray&, const Texture&);
		Entity(const Rectangle&, const Texture&);

		virtual Entity& operator=(const Entity&);

		void setPosition(const Vec2f&);
		void translate(const Vec2f&);
		const Vec2f& getPosition();

		void setScale(const Vec2f&);
		void scale(const Vec2f&);
		const Vec2f& getScale();

		void setTexture(const Texture&);
		virtual void draw();


	private:
		Uniforms	uniforms;
		VertexArray	vertexArray;
		Texture		texture;
	};
}
#endif