#pragma once

#include <MinecraftGL.hpp>

#include "Player/Controller.hpp"

class GameLayer : public MinecraftGL::Layer
{
public:
	GameLayer();

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(MinecraftGL::Timestep pStep) override;
	void OnEvent(MinecraftGL::Event& pEvent) override;

private:
	Controller m_Controller;

	MinecraftGL::Shader m_Shaders;
	MinecraftGL::Model m_Model;
};