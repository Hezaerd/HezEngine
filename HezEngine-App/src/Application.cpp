#include <HezEngine.hpp>
#include <HezEngine/Core/EntryPoint.hpp>

#include "EditorLayer.hpp"

namespace HezEngine
{
	class Game : public Application
	{
	public:

		Game()
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication()
	{
		return new Game();
	}
}