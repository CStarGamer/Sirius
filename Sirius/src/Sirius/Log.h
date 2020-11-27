#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sirius {
	class SIRIUS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SR_CORE_TRACE(...)		::Sirius::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SR_CORE_INFO(...)		::Sirius::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SR_CORE_WARN(...)		::Sirius::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SR_CORE_ERROR(...)		::Sirius::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SR_CORE_FATAL(...)		::Sirius::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SR_TRACE(...)		::Sirius::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SR_INFO(...)		::Sirius::Log::GetClientLogger()->info(__VA_ARGS__)
#define SR_WARN(...)		::Sirius::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SR_ERROR(...)		::Sirius::Log::GetClientLogger()->error(__VA_ARGS__)
#define SR_FATAL(...)		::Sirius::Log::GetClientLogger()->fatal(__VA_ARGS__)
