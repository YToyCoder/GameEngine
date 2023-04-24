#pragma once

#include<memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace GameEngine 
{
	class HAZEL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core
#define HZ_CORE_TRACE(...) ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::GameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client
#define HZ_TRACE(...) ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...) ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...) ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...) ::GameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

