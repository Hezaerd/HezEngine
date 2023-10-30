#pragma once

#include "HezEngine/Core/Application.hpp"

extern HezEngine::Application* HezEngine::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace HezEngine
{
	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			InitializeCore();

			Application* app = CreateApplication(argc, argv);
			HEZ_CORE_ASSERT(app, "Client application is null!");
			app->Run();
			delete app;
			
			ShutdownCore();
		}
		return 0;
	}
}

int main(int argc, char** argv)
{
	return HezEngine::Main(argc, argv);
}
