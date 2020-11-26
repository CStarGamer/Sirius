#pragma once

#ifdef SR_PLATFORM_WINDOWS
	#ifdef SR_BUILD_DLL
		#define SIRIUS_API __declspec(dllexport)
	#else
		#define SIRIUS_API __declspec(dllimport)
	#endif // SR_BUILD_DLL
#else
	#error Sirius currently only supports Windows!
#endif // SR_PLATFORM_WINDOWS
