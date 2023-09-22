#include <mglpch.hpp>
#include "MinecraftGL/Renderer/Camera.hpp"

#include <MGLMaths/Utils.hpp>

namespace MinecraftGL
{
	Camera::Camera(float pFOV, float pAspectRatio, float pNear, float pFar)
	{
		SetProjection(pFOV, pAspectRatio, pNear, pFar);
	}

	void Camera::OnUpdate(Timestep /*pStep*/)
	{
		UpdateViewMatrix();
	}

	void Camera::SetProjection(float pFOV, float pAspectRatio, float pNear, float pFar)
	{
		m_ProjectionMatrix = MGLMaths::Mat4f::Perspective(pFOV, pAspectRatio, pNear, pFar);
	}

	MGLMaths::Vec3f Camera::GetUpDirection() const
	{
		return MGLMaths::Vec3f::Normalize(MGLMaths::Vec3f::Cross(GetRightDirection(), GetForwardDirection()));
	}

	MGLMaths::Vec3f Camera::GetRightDirection() const
	{
		return MGLMaths::Vec3f::Normalize(MGLMaths::Vec3f::Cross(GetForwardDirection(), MGLMaths::Vec3f::Up));
	}

	MGLMaths::Vec3f Camera::GetForwardDirection() const
	{
		MGLMaths::Vec3f lForwardDirection;

		lForwardDirection.x = -cos(MGLMaths::toRadians(m_Rotation.x)) * sin(MGLMaths::toRadians(m_Rotation.y));
		lForwardDirection.y = sin(MGLMaths::toRadians(m_Rotation.x));
		lForwardDirection.z = cos(MGLMaths::toRadians(m_Rotation.x)) * cos(MGLMaths::toRadians(m_Rotation.y));

		return MGLMaths::Vec3f::Normalize(lForwardDirection);
	}

	void Camera::UpdateViewMatrix()
	{
		MGLMaths::Mat4f lTempMatrix = MGLMaths::Mat4f::Identity;

		lTempMatrix = MGLMaths::Mat4f::Rotate(lTempMatrix, m_Rotation);
		lTempMatrix = MGLMaths::Mat4f::Translate(lTempMatrix, m_Position);

		m_ViewMatrix = MGLMaths::Mat4f::Inverse(lTempMatrix);
	}

	void Camera::UpdateProjectionMatrix()
	{
		m_ProjectionMatrix = MGLMaths::Mat4f::Perspective(90.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
	}
}