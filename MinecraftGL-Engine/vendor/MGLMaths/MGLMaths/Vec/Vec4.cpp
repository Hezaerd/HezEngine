#include "Vec4.hpp"
#include <cmath>

#include <stdexcept>
#include <string>
#include <algorithm>

namespace MGLMaths
{
	Vec4f::Vec4f(float pX, float pY, float pZ, float pW) : x(pX), y(pY), z(pZ), w(pW) {}
	Vec4f::Vec4f(float pX) : x(pX), y(pX), z(pX), w(pX) {}
	Vec4f::Vec4f() : x(0), y(0), z(0), w(0) {}
	Vec4f::Vec4f(const Vec4f& pOther) : x(pOther.x), y(pOther.y), z(pOther.z), w(pOther.w) {}
	Vec4f Vec4f::operator=(const Vec4f& pOther) { x = pOther.x; y = pOther.y; z = pOther.z; w = pOther.w; return *this; }

	const Vec4f Vec4f::Zero(0.f, 0.f, 0.f, 0.f);
	const Vec4f Vec4f::One(1.f, 1.f, 1.f, 1.f);

	Vec4f Vec4f::operator+(const Vec4f& pOther) const { return Vec4f(x + pOther.x, y + pOther.y, z + pOther.z, w + pOther.w); }
	Vec4f Vec4f::operator-(const Vec4f& pOther) const { return Vec4f(x - pOther.x, y - pOther.y, z - pOther.z, w - pOther.w); }
	Vec4f Vec4f::operator*(const Vec4f& pOther) const { return Vec4f(x * pOther.x, y * pOther.y, z * pOther.z, w * pOther.w); }
	Vec4f Vec4f::operator/(const Vec4f& pOther) const
	{
		if (pOther.x == 0 || pOther.y == 0 || pOther.z == 0 || pOther.w == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec4f(x / pOther.x, y / pOther.y, z / pOther.z, w / pOther.w);
	}

	Vec4f Vec4f::operator+(float pOther) const { return Vec4f(x + pOther, y + pOther, z + pOther, w + pOther); }
	Vec4f Vec4f::operator-(float pOther) const { return Vec4f(x - pOther, y - pOther, z - pOther, w - pOther); }
	Vec4f Vec4f::operator*(float pOther) const { return Vec4f(x * pOther, y * pOther, z * pOther, w * pOther); }
	Vec4f Vec4f::operator/(float pOther) const
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec4f(x / pOther, y / pOther, z / pOther, w / pOther);
	}

	Vec4f& Vec4f::operator+=(const Vec4f& pOther) { x += pOther.x; y += pOther.y; z += pOther.z; w += pOther.w; return *this; }
	Vec4f& Vec4f::operator-=(const Vec4f& pOther) { x -= pOther.x; y -= pOther.y; z -= pOther.z; w -= pOther.w; return *this; }
	Vec4f& Vec4f::operator*=(const Vec4f& pOther) { x *= pOther.x; y *= pOther.y; z *= pOther.z; w *= pOther.w; return *this; }
	Vec4f& Vec4f::operator/=(const Vec4f& pOther)
	{
		if (pOther.x == 0 || pOther.y == 0 || pOther.z == 0 || pOther.w == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther.x; y /= pOther.y; z /= pOther.z; w /= pOther.w; return *this;
	}

	Vec4f& Vec4f::operator+=(float pOther) { x += pOther; y += pOther; z += pOther; w += pOther; return *this; }
	Vec4f& Vec4f::operator-=(float pOther) { x -= pOther; y -= pOther; z -= pOther; w -= pOther; return *this; }
	Vec4f& Vec4f::operator*=(float pOther) { x *= pOther; y *= pOther; z *= pOther; w *= pOther; return *this; }
	Vec4f& Vec4f::operator/=(float pOther)
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther; y /= pOther; z /= pOther; w /= pOther; return *this;
	}

	bool Vec4f::operator==(const Vec4f& pOther) const { return x == pOther.x && y == pOther.y && z == pOther.z && w == pOther.w; }
	bool Vec4f::operator!=(const Vec4f& pOther) const { return x != pOther.x || y != pOther.y || z != pOther.z || w != pOther.w; }

	std::ostream& operator<<(std::ostream& pStream, const Vec4f& pVec)
	{
		pStream << "Vec4f(" << pVec.x << ", " << pVec.y << ", " << pVec.z << ", " << pVec.w << ")";
		return pStream;
	}

	std::string Vec4f::ToString() const
	{
		return "Vec4f(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
	}

	float Vec4f::sqrMagnitude(const Vec4f& pVec)
	{
		return (pVec.x * pVec.x) + (pVec.y * pVec.y) + (pVec.z * pVec.z) + (pVec.w * pVec.w);
	}

	float Vec4f::Magnitude(const Vec4f& pVec)
	{
		return sqrt(sqrMagnitude(pVec));
	}

	float Vec4f::Dot(const Vec4f& pLeft, const Vec4f& pRight)
	{
		return (pLeft.x * pRight.x) + (pLeft.y * pRight.y) + (pLeft.z * pRight.z) + (pLeft.w * pRight.w);
	}

	float Vec4f::sqrDistance(const Vec4f& pLeft, const Vec4f& pRight)
	{
		return sqrMagnitude(pLeft - pRight);
	}

	float Vec4f::Distance(const Vec4f& pLeft, const Vec4f& pRight)
	{
		return Magnitude(pLeft - pRight);
	}

	float Vec4f::Angle(const Vec4f& pLeft, const Vec4f& pRight)
	{
		return acos(Dot(pLeft, pRight) / (Magnitude(pLeft) * Magnitude(pRight)));
	}

	Vec4f Vec4f::Normalize(const Vec4f& pVec)
	{
		return pVec / Magnitude(pVec);
	}

	Vec4f Vec4f::Lerp(const Vec4f& pLeft, const Vec4f& pRight, float pTime)
	{
		return pLeft + (pRight - pLeft) * pTime;
	}

	Vec4f Vec4f::Slerp(const Vec4f& pLeft, const Vec4f& pRight, float pTime)
	{
		float dot = Dot(pLeft, pRight);
		dot = std::clamp(dot, -1.0f, 1.0f);

		float theta = acos(dot) * pTime;
		Vec4f relativeVec = pRight - pLeft * dot;
		relativeVec = Normalize(relativeVec);

		return ((pLeft * cos(theta)) + (relativeVec * sin(theta)));
	}

	Vec4f Vec4f::Project(const Vec4f& pVec, const Vec4f& pOnNormal)
	{
		return pOnNormal * (Dot(pVec, pOnNormal) / sqrMagnitude(pOnNormal));
	}

	Vec4f Vec4f::Reflect(const Vec4f& pVec, const Vec4f& pNormal)
	{
		return pVec - (pNormal * 2 * Dot(pVec, pNormal));
	}

	float Vec4f::sqrMagnitude()
	{
		return sqrMagnitude(*this);
	}

	float Vec4f::Magnitude()
	{
		return Magnitude(*this);
	}

	float Vec4f::Dot(const Vec4f& pOther)
	{
		return Dot(*this, pOther);
	}

	float Vec4f::sqrDistance(const Vec4f& pOther)
	{
		return sqrDistance(*this, pOther);
	}

	float Vec4f::Distance(const Vec4f& pOther)
	{
		return Distance(*this, pOther);
	}

	float Vec4f::Angle(const Vec4f& pOther)
	{
		return Angle(*this, pOther);
	}

	Vec4f Vec4f::Normalize()
	{
		return Normalize(*this);
	}

	Vec4f Vec4f::Lerp(const Vec4f& pOther, float pTime)
	{
		return Lerp(*this, pOther, pTime);
	}

	Vec4f Vec4f::Slerp(const Vec4f& pOther, float pTime)
	{
		return Slerp(*this, pOther, pTime);
	}

	Vec4f Vec4f::Project(const Vec4f& pOnNormal)
	{
		return Project(*this, pOnNormal);
	}

	Vec4f Vec4f::Reflect(const Vec4f& pNormal)
	{
		return Reflect(*this, pNormal);
	}
}