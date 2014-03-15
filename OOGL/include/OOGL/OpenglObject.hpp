#ifndef OPENGLOBJECT_HPP
#define OPENGLOBJECT_HPP

#include "../GLEW/glew.h"
#include <vector>
#include <memory>

namespace gl
{
	struct OpenglHandle
	{
		virtual void bind() const = 0;
		virtual ~OpenglHandle() {}
	};


	class OpenglObject
	{
	protected:
		std::vector<std::shared_ptr<OpenglHandle>> glHandles;

	public:
		virtual void bind() const
		{
			for(const auto& i : glHandles)
				i->bind();
		}

		virtual void destroy()
		{
			glHandles.clear();
		}

		virtual ~OpenglObject() {}
	};
}
#endif