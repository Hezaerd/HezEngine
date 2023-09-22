#pragma once

#include <MinecraftGL.hpp>

class Controller
{
public:
	Controller();

	void OnUpdate(MinecraftGL::Timestep pStep);
	void OnEvent(MinecraftGL::Event& pEvent);

	MinecraftGL::Camera& GetCamera() { return m_Camera; }
	const MinecraftGL::Camera& GetCamera() const { return m_Camera; }

	void OnMouseMoved(MinecraftGL::MouseMovedEvent& pEvent);
	void OnKeyPressed(MinecraftGL::KeyPressedEvent& pEvent);

private:
	MinecraftGL::Camera m_Camera;

	float m_MouseSensitivity = 0.1f;
	float m_MovementSpeed = 5.0f;
};