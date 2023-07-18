#include "MinecraftGL/Scene/Camera.hpp"
namespace MinecraftGL
{
    Camera::Camera()
    {
        //create view matrix & projection
    }

    Camera::Camera(MGLMaths::Vec3f pPosition, MGLMaths::Vec3f pUp)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::SetPosition(const MGLMaths::Vec3f& position)
    {
    }

    void Camera::SetRotation(const MGLMaths::Vec3f& rotation)
    {
    }

    const MGLMaths::Vec3f& Camera::GetPosition() const
    {
    }

    MGLMaths::Mat4f Camera::GetViewMatrix() const
    {
    }

    MGLMaths::Mat4f Camera::GetProjectionMatrix() const
    {
    }
}