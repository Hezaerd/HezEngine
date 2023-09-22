#pragma once

#include "MinecraftGL/Core/Base.hpp"
#include "MinecraftGL/Core/Application.hpp"

extern MinecraftGL::Application* MinecraftGL::CreateApplication();

int main(int /*argc*/, char** /*argv*/)
{
	MinecraftGL::Log::Init();
	MGL_CORE_WARN("Initialized Log!");

	auto app = MinecraftGL::CreateApplication();
	app->Run();
	delete app;
	MGL_CORE_CRITICAL("Application destroyed.");
}