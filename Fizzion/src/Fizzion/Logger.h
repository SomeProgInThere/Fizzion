#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>

namespace Fizzion
{
	class FIZZION_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Core logging macros
#define FZ_CORE_TRACE(...) ::Fizzion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FZ_CORE_INFO(...)  ::Fizzion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FZ_CORE_WARN(...)  ::Fizzion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FZ_CORE_ERROR(...) ::Fizzion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FZ_CORE_FATAL(...) ::Fizzion::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logging macros
#define FZ_TRACE(...) ::Fizzion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FZ_INFO(...)  ::Fizzion::Log::GetClientLogger()->info(__VA_ARGS__)
#define FZ_WARN(...)  ::Fizzion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FZ_ERROR(...) ::Fizzion::Log::GetClientLogger()->error(__VA_ARGS__)
#define FZ_FATAL(...) ::Fizzion::Log::GetClientLogger()->fatal(__VA_ARGS__)
