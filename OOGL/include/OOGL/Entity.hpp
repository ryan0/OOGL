//////////////////////////////////////
//           Entity                 //
//////////////////////////////////////
/*

*/

#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "Vec2.hpp"
#include "Texture.hpp"
#include "Model.hpp"
#include "../GLEW/glew.h"
#include <vector>

namespace oogl
{
	class Shader;

	class Entity
	{
	public:
		Entity();
		Entity(const Entity&);
		Entity(const Model&, const Texture&);
		virtual Entity& operator=(const Entity&);
		~Entity();

		void setPosition(const Vec2f&);
		void translate(const Vec2f&);
		const Vec2f& getPosition();

		void setScale(const Vec2f&);
		void scale(const Vec2f&);
		const Vec2f& getScale();

		void setTexture(const Texture&);
		virtual void draw();


	private:
		GLuint ID, bufferID;
		Shader* shader;
		Texture texture;
		Model model;
	};
}
#endif