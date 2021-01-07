#pragma once

#include <memory>

// Platform detection (using predefined macros)
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64 */
		#define SR_PLATFORM_WINDOWS
	#else
		/* Windows x86 */
		#error "x86 builds are not supported!"	
	#endif // _WIN64
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define SR_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define SR_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
	/* We also have to check __ANDROID__ before __linux__
	 * since android is based on the linux kernel
	 * it has __linux__ defined */
	#elif defined(__ANDROID__)
		#define SR_PLATFORM_ANDROID
		#error "Android is not supported!"
	#elif defined(__linux__)
		#define SR_PLATFORM_LINUX
		#error "Linux is not supported!"
	#else
		/* Unknown compiler/platform */
		#error "Unknown platform!"
#endif // End of platform detection (_WIN32)

// DLL support
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
	#define SR_ASSERT(x, ...) {if (!(x)) { SR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define SR_CORE_ASSERT(x, ...) {if (!(x)) { SR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define SR_ASSERT(x, ...)
	#define SR_CORE_ASSERT(x, ...)
#endif // SR_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define SR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Sirius {

	// Scope
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	// Ref
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	
}