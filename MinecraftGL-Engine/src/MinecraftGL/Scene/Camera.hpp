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

        const MGLMaths::Vec3f& GetPosition() const;

        MGLMaths::Mat4f GetViewMatrix() const;
        MGLMaths::Mat4f GetProjectionMatrix() const;

        void ProcessMouseInput(const float& pDeltaTime, const float& pXOffset, const float& pYOffset, const bool& pConstrainPitch = true);

    private:
        void UpdateCameraVectors();

    public:
        static constexpr float FOV = 70.0f;
        static constexpr float NEAR_PLANE = 0.1f;
        static constexpr float FAR_PLANE = 1000.0f;

        float mYaw = -90.0f;
        float mPitch = 0.0f;
        float mRoll = 0.0f;

        float mSensitivty = 1.0f;

        MGLMaths::Vec3f mPosition;
        MGLMaths::Vec3f mFront, mUp, mRight, mWorldUp;
        MGLMaths::Mat4f mViewMatrix, mProjectionMatrix;
    };
}