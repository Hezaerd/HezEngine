#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Application.hpp"

extern HezEngine::Application* HezEngine::CreateApplication();

int main(int /*argc*/, char** /*argv*/)
{
	HezEngine::Log::Init();
	HEZ_CORE_WARN("Initialized Log!");

	auto app = HezEngine::CreateApplication();
	app->Run();
	delete app;
	HEZ_CORE_CRITICAL("Application destroyed.");
}