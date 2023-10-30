#include "EditorLayer.hpp"

#include "HezEngine/Core/EntryPoint.hpp"

class HezEngineApplication : public HezEngine::Application
{
public:
	HezEngineApplication(const HezEngine::ApplicationSpecification& pSpecification)
		: Application(pSpecification)
	{
		PushLayer(new HezEngine::EditorLayer());
	}
};

HezEngine::Application* HezEngine::CreateApplication(int argc, char** argv)
{
	HezEngine::ApplicationSpecification appSpec;
	appSpec.Name = "HezEngine Editor";
	appSpec.WindowWidth = 1600;
	appSpec.WindowHeight = 900;
	appSpec.StartMaximized = true;
	appSpec.VSync = true;

	return new HezEngineApplication(appSpec);
}
