#include "EditorLayer.hpp"

EditorLayer::EditorLayer()
	: Layer("EditorLayer")
{
}

void EditorLayer::OnAttach()
{
	HEZ_INFO("Layer {0} attached", GetName());
}

void EditorLayer::OnDetach()
{
	HEZ_INFO("Layer {0} detached", GetName());
}

void EditorLayer::OnUpdate(HezEngine::Timestep /*pStep*/)
{
}

void EditorLayer::OnEvent(HezEngine::Event& /*pEvent*/)
{
}
