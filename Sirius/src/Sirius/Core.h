#pragma once

#include <memory>

#ifdef SR_PLATFORM_WINDOWS
	#if SR_DYNAMIC_LINK
		#ifdef SR_BUILD_DLL
			#define SIRIUS_API __declspec(dllexport)
		#else
			#define SIRIUS_API __declspec(dllimport)
		#endif // SR_BUILD_DLL
	#else
		#define SIRIUS_API
	#endif // SR_DYNAMIC_LINK
#else
	#error Sirius currently only supports Windows!
#endif // SR_PLATFORM_WINDOWS

#define SR_ENABLE_ASSERTS
#ifdef SR_ENABLE_ASSERTS
	#define SR_ASSERT(x, ...) {if (!x) { SR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define SR_CORE_ASSERT(x, ...) {if (!x) { SR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define SR_ASSERT(x, ...)
	#define SR_CORE_ASSERT(x, ...)
#endif // SR_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define SR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Sirius {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	
}