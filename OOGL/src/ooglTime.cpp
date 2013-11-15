#include <OOGL/ooglTime.hpp>
#include <Windows.h>

namespace oogl
{
	double getTime()
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return	double(time.wMilliseconds) +
				double(time.wSecond) * 1000 +
				double(time.wMinute) * 60 * 1000;
	}
}