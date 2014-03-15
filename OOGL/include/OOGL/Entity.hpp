#ifndef OOGLENTITY_HPP
#define OOGLENTITY_HPP

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"
#include "../GLEW/glew.h"
#include <vector>

namespace gl
{
	class Entity : virtual public VertexArray, virtual public Texture
	{
	public:
		Entity();
		Entity(const VertexArray&, const Texture&);

		virtual void bind() const;
		virtual void destroy();
		void draw() const;
	};
}
#endif