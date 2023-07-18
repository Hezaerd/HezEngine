#pragma once
#include "MGLMaths/MGLMaths.hpp"

namespace MinecraftGL
{
    class Camera
    {
    public:
        Camera();
        Camera(MGLMaths::Vec3f pPosition, MGLMaths::Vec3f pUp);
        ~Camera();

        void SetPosition(const MGLMaths::Vec3f& position);
        void SetRotation(const MGLMaths::Vec3f& rotation);

        const MGLMaths::Vec3f& GetPosition() const;

        MGLMaths::Mat4f GetViewMatrix() const;
        MGLMaths::Mat4f GetProjectionMatrix() const;

    public:
        static constexpr float FOV = 70.0f;
        static constexpr float NEAR_PLANE = 0.1f;
        static constexpr float FAR_PLANE = 1000.0f;

        MGLMaths::Vec3f mPosition;
        MGLMaths::Vec3f mFront, mUp, mRight, mWorldUp;
    };
}