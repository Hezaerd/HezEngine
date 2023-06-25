#pragma once

#include "MinecraftGL/Core/Base.hpp"

namespace MinecraftGL
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}