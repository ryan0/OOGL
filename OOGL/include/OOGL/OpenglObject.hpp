#ifndef OPENGLOBJECT_HPP
#define OPENGLOBJECT_HPP

#include <vector>
#include <memory>

namespace gl
{
	class OpenglObject
	{
	public:
		virtual void bind() const = 0;
		virtual void destroy() = 0;
		virtual ~OpenglObject() {}
	};
}
#endif