#pragma once

#include <ostream>

namespace MGLMaths
{
	class Vec4f
	{
	public:
		float x, y, z, w;

	public:
		Vec4f(float pX, float pY, float pZ, float pW);
		Vec4f(float pX);
		Vec4f();
		Vec4f(const Vec4f& pOther);
		Vec4f operator=(const Vec4f& pOther);

		static const Vec4f Zero;
		static const Vec4f One;

		Vec4f operator+(const Vec4f& pOther) const;
		Vec4f operator-(const Vec4f& pOther) const;
		Vec4f operator*(const Vec4f& pOther) const;
		Vec4f operator/(const Vec4f& pOther) const;

		Vec4f operator+(float pOther) const;
		Vec4f operator-(float pOther) const;
		Vec4f operator*(float pOther) const;
		Vec4f operator/(float pOther) const;

		Vec4f& operator+=(const Vec4f& pOther);
		Vec4f& operator-=(const Vec4f& pOther);
		Vec4f& operator*=(const Vec4f& pOther);
		Vec4f& operator/=(const Vec4f& pOther);

		Vec4f& operator+=(float pOther);
		Vec4f& operator-=(float pOther);
		Vec4f& operator*=(float pOther);
		Vec4f& operator/=(float pOther);

		bool operator==(const Vec4f& pOther) const;
		bool operator!=(const Vec4f& pOther) const;

		std::ostream& operator<<(std::ostream& pStream) const;
		std::string ToString() const;

		static float sqrMagnitude(const Vec4f& pVec);
		static float Magnitude(const Vec4f& pVec);
		static float Dot(const Vec4f& pLeft, const Vec4f& pRight);
		static float sqrDistance(const Vec4f& pLeft, const Vec4f& pRight);
		static float Distance(const Vec4f& pLeft, const Vec4f& pRight);
		static float Angle(const Vec4f& pLeft, const Vec4f& pRight);

		static Vec4f Normalize(const Vec4f& pVec);
		static Vec4f Lerp(const Vec4f& pLeft, const Vec4f& pRight, float pTime);
		static Vec4f Slerp(const Vec4f& pLeft, const Vec4f& pRight, float pTime);
		static Vec4f Project(const Vec4f& pVec, const Vec4f& pOnNormal);
		static Vec4f Reflect(const Vec4f& pVec, const Vec4f& pNormal);

		float sqrMagnitude();
		float Magnitude();
		float Dot(const Vec4f& pOther);
		float sqrDistance(const Vec4f& pOther);
		float Distance(const Vec4f& pOther);
		float Angle(const Vec4f& pOther);

		Vec4f Normalize();
		Vec4f Lerp(const Vec4f& pOther, float pTime);
		Vec4f Slerp(const Vec4f& pOther, float pTime);
		Vec4f Project(const Vec4f& pOnNormal);
		Vec4f Reflect(const Vec4f& pNormal);
	};
}