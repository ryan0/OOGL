#include "ooglTime.h"
#include <Windows.h>

namespace oogl
{
	float getTime()
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return	float(time.wMilliseconds) +
				float(time.wSecond) * 1000 +
				float(time.wMinute) * 60 * 1000 +
				float(time.wHour) * 60 * 60 * 1000;
	}
}