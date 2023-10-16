#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Debug/LogCustomFormatters.hpp"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

#include <map>

namespace HezEngine
{
	class Log
	{
	public:
		enum class Type : uint8_t
		{
			Core = 0, Client = 1
		};
		
		enum class Level : uint8_t
		{
			Trace = 0, Info = 1, Warn = 2, Error = 3, Fatal = 4
		};
		
		struct TagDetails
		{
			bool Enabled = true;
			Level levelFilter = Level::Trace;
		};

	public:
		static void Init();
		static void Shutdown();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		inline static bool HasTag(const std::string& pTag) { return s_EnabledTags.find(pTag) != s_EnabledTags.end(); }
		static std::map<std::string, TagDetails>& GetEnabledTags() { return s_EnabledTags; }

		template<typename... Args>
		static void PrintMessage(Log::Type pType, Log::Level pLevel, std::string_view pTag, Args&&... pArgs);

		template<typename... Args>
		static void PrintAssertMessage(Log::Type pType, std::string_view pPrefix, Args&&... pArgs);
		
	public:
		// Enum utils
		static const char* LevelToString(Level pLevel)
		{
			switch (pLevel)
			{
				case Level::Trace: return "Trace";
				case Level::Info:  return "Info";
				case Level::Warn:  return "Warn";
				case Level::Error: return "Error";
				case Level::Fatal: return "Fatal";
			}
			return "";
		}

		static Level LevelFromString(std::string_view pString)
		{
			if (pString == "Trace") return Level::Trace;
			if (pString == "Info")  return Level::Info;
			if (pString == "Warn")  return Level::Warn;
			if (pString == "Error") return Level::Error;
			if (pString == "Fatal") return Level::Fatal;

			return Level::Trace;
		}

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

		inline static std::map<std::string, TagDetails> s_EnabledTags;
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tagged logs (prefer these!)                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Core logging
#define HEZ_CORE_TRACE_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Trace, tag, __VA_ARGS__)
#define HEZ_CORE_INFO_TAG(tag, ...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Info, tag, __VA_ARGS__)
#define HEZ_CORE_WARN_TAG(tag, ...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Warn, tag, __VA_ARGS__)
#define HEZ_CORE_ERROR_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Error, tag, __VA_ARGS__)
#define HEZ_CORE_FATAL_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Fatal, tag, __VA_ARGS__)

// Client logging
#define HEZ_TRACE_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Trace, tag, __VA_ARGS__)
#define HEZ_INFO_TAG(tag, ...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Info, tag, __VA_ARGS__)
#define HEZ_WARN_TAG(tag, ...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Warn, tag, __VA_ARGS__)
#define HEZ_ERROR_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Error, tag, __VA_ARGS__)
#define HEZ_FATAL_TAG(tag, ...) ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Fatal, tag, __VA_ARGS__)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Core Logging
#define HEZ_CORE_TRACE(...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Trace, "", __VA_ARGS__)
#define HEZ_CORE_INFO(...)   ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Info, "", __VA_ARGS__)
#define HEZ_CORE_WARN(...)   ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Warn, "", __VA_ARGS__)
#define HEZ_CORE_ERROR(...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Error, "", __VA_ARGS__)
#define HEZ_CORE_FATAL(...)  ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Core, ::HezEngine::Log::Level::Fatal, "", __VA_ARGS__)

// Client Logging
#define HEZ_TRACE(...)   ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Trace, "", __VA_ARGS__)
#define HEZ_INFO(...)    ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Info, "", __VA_ARGS__)
#define HEZ_WARN(...)    ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Warn, "", __VA_ARGS__)
#define HEZ_ERROR(...)   ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Error, "", __VA_ARGS__)
#define HEZ_FATAL(...)   ::HezEngine::Log::PrintMessage(::HezEngine::Log::Type::Client, ::HezEngine::Log::Level::Fatal, "", __VA_ARGS__)


namespace HezEngine
{
	template<typename... Args>
	void Log::PrintMessage(Log::Type pType, Log::Level pLevel, std::string_view pTag, Args&&... pArgs)
	{
		auto detail = s_EnabledTags[std::string(pTag)];
		if (detail.Enabled && detail.levelFilter <= pLevel)
		{
			auto& logger = (pType == Type::Core) ? GetCoreLogger() : GetClientLogger();
			std::string logString = pTag.empty() ? "{0}{1}" : "[{0}] {1}";
			switch (pLevel)
			{
				case Level::Trace:
					logger->trace(logString, pTag, fmt::format(std::forward<Args>(pArgs)...));
					break;
				case Level::Info:
					logger->info(logString, pTag, fmt::format(std::forward<Args>(pArgs)...));
					break;
				case Level::Warn:
					logger->warn(logString, pTag, fmt::format(std::forward<Args>(pArgs)...));
					break;
				case Level::Error:
					logger->error(logString, pTag, fmt::format(std::forward<Args>(pArgs)...));
					break;
				case Level::Fatal:
					logger->critical(logString, pTag, fmt::format(std::forward<Args>(pArgs)...));
					break;
			}
		}
	}

	template<typename... Args>
	void Log::PrintAssertMessage(Log::Type pType, std::string_view pPrefix, Args&&... pArgs)
	{
		auto& logger = (pType == Type::Core) ? GetCoreLogger() : GetClientLogger();
		logger->error("{0}: {1}", pPrefix, fmt::format(std::forward<Args>(pArgs)...));
	}

	template<>
	inline void Log::PrintAssertMessage(Log::Type pType, std::string_view pPrefix)
	{
		auto& logger = (pType == Type::Core) ? GetCoreLogger() : GetClientLogger();
		logger->error("{0}", pPrefix);
	}
}
