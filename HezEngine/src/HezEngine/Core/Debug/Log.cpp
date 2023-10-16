#include "hezpch.hpp"
#include "HezEngine/Core/Debug/Log.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <filesystem>

namespace HezEngine
{
	Ref<spdlog::logger> Log::s_CoreLogger;
	Ref<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		std::string logsDirectory = "logs";
		if (!std::filesystem::exists(logsDirectory))
			std::filesystem::create_directory(logsDirectory);

		std::vector<spdlog::sink_ptr> hezengineSinks =
		{
			CreateRef<spdlog::sinks::basic_file_sink_mt>("logs/HezEngine.log", true),
			CreateRef<spdlog::sinks::stdout_color_sink_mt>()
		};

		std::vector<spdlog::sink_ptr> clientSinks =
		{
			CreateRef<spdlog::sinks::basic_file_sink_mt>("logs/HezEngine-Editor.log", true),
			CreateRef<spdlog::sinks::stdout_color_sink_mt>()
		};

		hezengineSinks[0]->set_pattern("[%T] [%l] %n: %v");
		clientSinks[0]->set_pattern("[%T] [%l] %n: %v");

		hezengineSinks[1]->set_pattern("%^[%T] %n: %v%$");
		clientSinks[1]->set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = CreateRef<spdlog::logger>("HezEngine", begin(hezengineSinks), end(hezengineSinks));
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = CreateRef<spdlog::logger>("HezEngine-Editor", begin(clientSinks), end(clientSinks));
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	void Log::Shutdown()
	{
		s_ClientLogger.reset();
		s_CoreLogger.reset();
		
		spdlog::drop_all();
	}
}
