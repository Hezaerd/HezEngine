#include <MinecraftGL.hpp>

class Sandbox : public MinecraftGL::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

MinecraftGL::Application* MinecraftGL::CreateApplication()
{
	return new Sandbox();
}