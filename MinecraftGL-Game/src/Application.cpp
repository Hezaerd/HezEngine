#include <MinecraftGL.hpp>

class TestLayer : public MinecraftGL::Layer
{
public:
	TestLayer()
		: Layer("Test")
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(MinecraftGL::Event& pEvent) override
	{
	}
};

class Sandbox : public MinecraftGL::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
	}

	~Sandbox()
	{
	}
};

MinecraftGL::Application* MinecraftGL::CreateApplication()
{
	return new Sandbox();
}