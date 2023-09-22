#include "GameLayer.hpp"

GameLayer::GameLayer()
	: Layer("GameLayer"),
	m_Shaders("basicShader", "shaders/vertex.vert", "shaders/fragment.frag"),
	m_Model("assets/models/cube.obj")
{
}

void GameLayer::OnAttach()
{
	MGL_INFO("Layer {0} attached", GetName());
}

void GameLayer::OnDetach()
{
	MGL_INFO("Layer {0} detached", GetName());
}

void GameLayer::OnUpdate(MinecraftGL::Timestep pStep)
{
	m_Controller.OnUpdate(pStep);

	MinecraftGL::RendererOpenGL::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	MinecraftGL::RendererOpenGL::Clear();

	{
		m_Shaders.Bind();

		m_Shaders.SetMat4("u_MVP", m_Model.GetModelMatrix() * m_Controller.GetCamera().GetViewProjection());
		m_Shaders.SetMat4("u_Model", m_Model.GetModelMatrix());

		m_Model.Draw();

		m_Shaders.Unbind();
	}

	// Debug output the camera position
	MGL_INFO("Camera Position: {0}", m_Controller.GetCamera().GetPosition().ToString());
}

void GameLayer::OnEvent(MinecraftGL::Event& pEvent)
{
	m_Controller.OnEvent(pEvent); // Pass the event to the controller
}