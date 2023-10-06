#pragma once

#include <ostream>

namespace MGLMaths
{
	class Vec2f
	{
	public:
		float x, y;

	public:
		Vec2f(float pX, float pY);
		Vec2f(float pX);
		Vec2f();
		Vec2f(const Vec2f& pOther);
		Vec2f operator=(const Vec2f& pOther);

		static const Vec2f Zero;
		static const Vec2f One;

		Vec2f operator+(const Vec2f& pOther) const;
		Vec2f operator-(const Vec2f& pOther) const;
		Vec2f operator*(const Vec2f& pOther) const;
		Vec2f operator/(const Vec2f& pOther) const;

		Vec2f operator+(float pOther) const;
		Vec2f operator-(float pOther) const;
		Vec2f operator*(float pOther) const;
		Vec2f operator/(float pOther) const;

		Vec2f& operator+=(const Vec2f& pOther);
		Vec2f& operator-=(const Vec2f& pOther);
		Vec2f& operator*=(const Vec2f& pOther);
		Vec2f& operator/=(const Vec2f& pOther);

		Vec2f& operator+=(float pOther);
		Vec2f& operator-=(float pOther);
		Vec2f& operator*=(float pOther);
		Vec2f& operator/=(float pOther);

		bool operator==(const Vec2f& pOther) const;
		bool operator!=(const Vec2f& pOther) const;

		std::string ToString() const;

		static float sqrMagnitude(const Vec2f& pVec); // sqrMagnitude == sqrLength
		static float Magnitude(const Vec2f& pVec); // Magnitude == Length
		static float Dot(const Vec2f& pLeft, const Vec2f& pRight);
		static float sqrDistance(const Vec2f& pLeft, const Vec2f& pRight);
		static float Distance(const Vec2f& pLeft, const Vec2f& pRight);
		static float Angle(const Vec2f& pLeft, const Vec2f& pRight);

		static Vec2f Normalize(const Vec2f& pVec);
		static Vec2f Lerp(const Vec2f& pStart, const Vec2f& pEnd, float pDelta);
		static Vec2f Min(const Vec2f& pLeft, const Vec2f& pRight);
		static Vec2f Max(const Vec2f& pLeft, const Vec2f& pRight);

		float sqrMagnitude();
		float Magnitude();
		float Dot(const Vec2f& pOther);
		float sqrDistance(const Vec2f& pOther);
		float Distance(const Vec2f& pOther);
		float Angle(const Vec2f& pOther);

		void Normalize();
		void Lerp(const Vec2f& pEnd, float pDelta);
		void Min(const Vec2f& pOther);
		void Max(const Vec2f& pOther);
	};
}