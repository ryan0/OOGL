//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "Vec2.hpp"
#include "Uniforms.hpp"
#include "../GLEW/glew.h"
#include <vector>

namespace oogl
{
	class VertexArray;
	class Rectangle;
	class Texture;

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
		Uniforms			uniforms;
		const VertexArray*	vertexArray;
		const Texture*		texture;
	};
}
#endif