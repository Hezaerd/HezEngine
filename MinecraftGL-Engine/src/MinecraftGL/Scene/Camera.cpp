#include "mglpch.hpp"
#include "MinecraftGL/Scene/Camera.hpp"
#include "MinecraftGL/Core/Application.hpp"
#include "MGLMaths/Utils.hpp"
namespace MinecraftGL
{
	Camera::Camera()
	{
		//create view matrix & projection
	}

	Camera::Camera(MGLMaths::Vec3f pPosition, MGLMaths::Vec3f pUp)
	{
		mPosition = pPosition;
		mWorldUp = pUp;

		mFront = MGLMaths::Vec3f(0.0f, 0.0f, -1.0f);

		mUp = pUp;

		mRight = MGLMaths::Vec3f(1.0f, 0.0f, 0.0f);

		UpdateCameraVectors();

		mViewMatrix = MGLMaths::Mat4f::LookAt(mPosition, mPosition + mFront, mUp);

		mProjectionMatrix = MGLMaths::Mat4f::Perspective(FOV, Application::Get().GetWindow().GetAspectRatio(), NEAR_PLANE, FAR_PLANE);
	}

	Camera::~Camera()
	{
	}

	void Camera::SetPosition(const MGLMaths::Vec3f& pPosition)
	{
		mPosition = pPosition;
	}

	const MGLMaths::Vec3f& Camera::GetPosition() const
	{
		return mPosition;
	}

	MGLMaths::Mat4f Camera::GetViewMatrix() const
	{
		return mViewMatrix;
	}

	MGLMaths::Mat4f Camera::GetProjectionMatrix() const
	{
		return mProjectionMatrix;
	}

	void Camera::ProcessMouseInput(const float& pDeltaTime, const float& pXOffset, const float& pYOffset, const bool& pConstrainPitch /*= true*/)
	{
		mYaw += pXOffset * pDeltaTime * mSensitivty;
		mPitch += pYOffset * pDeltaTime * mSensitivty;

		if (pConstrainPitch)
		{
			if (mPitch > 89.0f)
			{
				mPitch = 89.0f;
			}
			if (mPitch < -89.0f)
			{
				mPitch = -89.0f;
			}
		}

		if (mYaw > 360.0f)
		{
			mYaw -= 360.0f;
		}
		if (mYaw < -360.0f)
		{
			mYaw += 360.0f;
		}

		UpdateCameraVectors();
	}

	void Camera::UpdateCameraVectors()
	{
		MGLMaths::Vec3f front;
		front.x = static_cast<float>(cos(MGLMaths::toRadians(mYaw)) * cos(MGLMaths::toRadians(mPitch)));
		front.y = static_cast<float>(sin(MGLMaths::toRadians(mPitch)));
		front.z = static_cast<float>(sin(MGLMaths::toRadians(mYaw)) * cos(MGLMaths::toRadians(mPitch)));
		mFront = MGLMaths::Vec3f::Normalize(front);

		mRight = MGLMaths::Vec3f::Normalize(MGLMaths::Vec3f::Cross(mFront, mWorldUp));
		mUp = MGLMaths::Vec3f::Normalize(MGLMaths::Vec3f::Cross(mRight, mFront));

		//MGL_CORE_TRACE(mFront.ToString());
	}
}