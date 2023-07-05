#pragma once

#include <iostream>

namespace MGLMaths
{
	class Vec3f
	{
	public:
		float x, y, z;

	public:
		Vec3f(float pX, float pY, float pZ);
		Vec3f(float pX);
		Vec3f();
		Vec3f(const Vec3f& pOther);

		static const Vec3f Zero;
		static const Vec3f One;
		static const Vec3f Up;
		static const Vec3f Down;
		static const Vec3f Left;
		static const Vec3f Right;
		static const Vec3f Forward;
		static const Vec3f Backward;

		Vec3f operator+(const Vec3f& pOther) const;
		Vec3f operator-(const Vec3f& pOther) const;
		Vec3f operator*(const Vec3f& pOther) const;
		Vec3f operator/(const Vec3f& pOther) const;

		Vec3f operator+(float pOther) const;
		Vec3f operator-(float pOther) const;
		Vec3f operator*(float pOther) const;
		Vec3f operator/(float pOther) const;

		Vec3f& operator+=(const Vec3f& pOther);
		Vec3f& operator-=(const Vec3f& pOther);
		Vec3f& operator*=(const Vec3f& pOther);
		Vec3f& operator/=(const Vec3f& pOther);

		Vec3f& operator+=(float pOther);
		Vec3f& operator-=(float pOther);
		Vec3f& operator*=(float pOther);
		Vec3f& operator/=(float pOther);

		bool operator==(const Vec3f& pOther) const;
		bool operator!=(const Vec3f& pOther) const;

		std::ostream& operator<<(std::ostream& pStream) const;
		std::string ToString() const;

		static float sqrMagnitude(const Vec3f& pVec);
		static float Magnitude(const Vec3f& pVec);
		static float Dot(const Vec3f& pLeft, const Vec3f& pRight);
		static float sqrDistance(const Vec3f& pLeft, const Vec3f& pRight);
		static float Distance(const Vec3f& pLeft, const Vec3f& pRight);
		static float Angle(const Vec3f& pLeft, const Vec3f& pRight);

		static Vec3f Normalize(const Vec3f& pVec);
		static Vec3f Lerp(const Vec3f& pStart, const Vec3f& pEnd, float pDelta);
		static Vec3f Cross(const Vec3f& pLeft, const Vec3f& pRight);
		static Vec3f Project(const Vec3f& pVec, const Vec3f& pOnNormal);
		static Vec3f Reflect(const Vec3f& pVec, const Vec3f& pNormal);

		float sqrMagnitude();
		float Magnitude();
		float Dot(const Vec3f& pRight);
		float sqrDistance(const Vec3f& pRight);
		float Distance(const Vec3f& pRight);
		float Angle(const Vec3f& pRight);

		void Normalize();
		void Lerp(const Vec3f& pEnd, float pDelta);
		void Cross(const Vec3f& pRight);
		void Project(const Vec3f& pOnNormal);
		void Reflect(const Vec3f& pNormal);
	};
}