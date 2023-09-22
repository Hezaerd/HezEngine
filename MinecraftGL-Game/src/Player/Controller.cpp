#include "Controller.hpp"

Controller::Controller()
{
}

void Controller::OnUpdate(MinecraftGL::Timestep pStep)
{
	m_Camera.OnUpdate(pStep);
}

void Controller::OnEvent(MinecraftGL::Event& pEvent)
{
	MinecraftGL::EventDispatcher dispatcher(pEvent);
	//dispatcher.Dispatch<MinecraftGL::MouseMovedEvent>(MGL_BIND_EVENT_FN(Controller::OnMouseMoved));
	//dispatcher.Dispatch<MinecraftGL::KeyPressedEvent>(MGL_BIND_EVENT_FN(Controller::OnKeyPressed));
}

//void Controller::OnMouseMoved(MinecraftGL::MouseMovedEvent& pEvent)
//{
//	if (MinecraftGL::Input::IsMouseButtonPressed(MGL_MOUSE_BUTTON_RIGHT))
//	{
//		float xoffset = pEvent.GetXOffset() * m_MouseSensitivity;
//		float yoffset = pEvent.GetYOffset() * m_MouseSensitivity;
//
//		m_Camera.Yaw += xoffset;
//		m_Camera.Pitch += yoffset;
//
//		if (m_Camera.Pitch > 89.0f)
//			m_Camera.Pitch = 89.0f;
//		if (m_Camera.Pitch < -89.0f)
//			m_Camera.Pitch = -89.0f;
//	}
//}