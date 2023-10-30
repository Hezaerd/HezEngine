#include "hezpch.hpp"
#include "HezEngine/Core/Base.hpp"

#include "HezEngine/Core/Debug/Log.hpp"

#define HEZ_ENGINE_BUILD_ID "v.0.0.1a"

namespace HezEngine
{
	void InitializeCore()
	{
		Log::Init();

		HEZ_CORE_TRACE_TAG("Core", "HezEngine {}", HEZ_ENGINE_BUILD_ID);
		HEZ_CORE_TRACE_TAG("Core", "Initializing...");
	}

	void ShutdownCore()
	{
		HEZ_CORE_TRACE_TAG("Core", "Shutting down...");
		
		Log::Shutdown();
	}
}
