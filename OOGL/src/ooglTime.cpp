#include <OOGL/ooglTime.hpp>
#include <Windows.h>

namespace gl
{
	int getTime()
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return	int(time.wMilliseconds) +
				int(time.wSecond) * 1000 +
				int(time.wMinute) * 60 * 1000;
	}
}