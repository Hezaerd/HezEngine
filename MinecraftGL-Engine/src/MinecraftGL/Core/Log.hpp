#pragma once

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#pragma warning(pop)

namespace MinecraftGL
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Engine log
#define MGL_CORE_TRACE(...)    ::MinecraftGL::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MGL_CORE_INFO(...)     ::MinecraftGL::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MGL_CORE_WARN(...)     ::MinecraftGL::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MGL_CORE_ERROR(...)    ::MinecraftGL::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MGL_CORE_CRITICAL(...) ::MinecraftGL::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Game log
#define MGL_TRACE(...)         ::MinecraftGL::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MGL_INFO(...)          ::MinecraftGL::Log::GetClientLogger()->info(__VA_ARGS__)
#define MGL_WARN(...)          ::MinecraftGL::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MGL_ERROR(...)         ::MinecraftGL::Log::GetClientLogger()->error(__VA_ARGS__)
#define MGL_CRITICAL(...)      ::MinecraftGL::Log::GetClientLogger()->critical(__VA_ARGS__)