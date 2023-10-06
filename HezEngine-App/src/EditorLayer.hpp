#pragma once

#include <HezEngine.hpp>

class EditorLayer : public HezEngine::Layer
{
public:
	EditorLayer();

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(HezEngine::Timestep pStep) override;
	void OnEvent(HezEngine::Event& pEvent) override;

private:
};