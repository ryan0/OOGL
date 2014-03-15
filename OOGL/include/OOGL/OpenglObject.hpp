#ifndef OPENGLOBJECT_HPP
#define OPENGLOBJECT_HPP

#include <vector>
#include <memory>

namespace gl
{
	class OpenglObject
	{
	protected:
		struct OpenglHandle
		{
			virtual void bind() const = 0;
			virtual ~OpenglHandle() {}
		};
		std::vector<std::shared_ptr<OpenglHandle>> glHandles;

	public:
		virtual void bind() const
		{
			for(const auto& i : glHandles)
				i->bind();
		}
		virtual void destroy() {glHandles.clear();}
		virtual ~OpenglObject() = 0;
	};
	inline OpenglObject::~OpenglObject() {}
}
#endif