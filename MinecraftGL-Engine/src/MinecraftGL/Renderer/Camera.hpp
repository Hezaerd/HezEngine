#pragma once

#include "MinecraftGL/Core/Timestep.hpp"

#include <MGLMaths/MGLMaths.hpp>

namespace MinecraftGL
{
	class Camera
	{
	public:
		Camera() = default;
		Camera(float pFOV, float pAspectRatio, float pNear, float pFar);

		void OnUpdate(Timestep pStep);
		//void OnEvent(Event& pEvent); -- No event needed here! Keyboard and mouse events are handled in the game.

		void SetViewportSize(float pWidth, float pHeight);

		void SetProjection(float pFOV, float pAspectRatio, float pNear, float pFar);

		void SetPosition(const MGLMaths::Vec3f& pPosition) { m_Position = pPosition; }
		void SetRotation(const MGLMaths::Vec3f& pRotation) { m_Rotation = pRotation; }

		const MGLMaths::Vec3f& GetPosition() const { return m_Position; }
		const MGLMaths::Vec3f& GetRotation() const { return m_Rotation; }

		const MGLMaths::Mat4f& GetViewMatrix() const { return m_ViewMatrix; }
		const MGLMaths::Mat4f& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const MGLMaths::Mat4f& GetViewProjection() const { return m_ProjectionMatrix * m_ViewMatrix; }

		MGLMaths::Vec3f GetUpDirection() const;
		MGLMaths::Vec3f GetRightDirection() const;
		MGLMaths::Vec3f GetForwardDirection() const;

	private:
		void UpdateViewMatrix();
		void UpdateProjectionMatrix();

	private:
		MGLMaths::Vec3f m_Position;
		MGLMaths::Vec3f m_Rotation;

		MGLMaths::Mat4f m_ViewMatrix;
		MGLMaths::Mat4f m_ProjectionMatrix;

		float m_ViewPortWidth = 1600.0f, m_ViewPortHeight = 800.0f;
	};
}