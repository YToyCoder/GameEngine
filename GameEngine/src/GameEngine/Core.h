#pragma once

namespace GameEngine {
}

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else 
		#define HAZEL_API __declspec(dllimport)
	#endif
#else 
#error Hazel only support windows
#endif

#define Bit(x) (1 << x)
