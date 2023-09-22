#include <MinecraftGL.hpp>
#include <MinecraftGL/Core/EntryPoint.hpp>

#include "GameLayer.hpp"

namespace MinecraftGL
{
	class Game : public Application
	{
	public:

		Game()
		{
			PushLayer(new GameLayer());
		}
	};

	Application* CreateApplication()
	{
		return new Game();
	}
}