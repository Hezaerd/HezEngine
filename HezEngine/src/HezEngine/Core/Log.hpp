#pragma once

#include "HezEngine/Core/Base.hpp"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#pragma warning(pop)

namespace HezEngine
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Engine log
#define HEZ_CORE_TRACE(...)    ::HezEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HEZ_CORE_INFO(...)     ::HezEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HEZ_CORE_WARN(...)     ::HezEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HEZ_CORE_ERROR(...)    ::HezEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HEZ_CORE_CRITICAL(...) ::HezEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// App log
#define HEZ_TRACE(...)         ::HezEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HEZ_INFO(...)          ::HezEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HEZ_WARN(...)          ::HezEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HEZ_ERROR(...)         ::HezEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HEZ_CRITICAL(...)      ::HezEngine::Log::GetClientLogger()->critical(__VA_ARGS__)