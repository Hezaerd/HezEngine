#include "Vec3.hpp"
#include <cmath>

#include <stdexcept>
#include <string>

namespace MGLMaths
{
	Vec3f::Vec3f(float pX, float pY, float pZ) : x(pX), y(pY), z(pZ) {}
	Vec3f::Vec3f(float pX) : x(pX), y(pX), z(pX) {}
	Vec3f::Vec3f() : x(0), y(0), z(0) {}
	Vec3f::Vec3f(const Vec3f& pOther) : x(pOther.x), y(pOther.y), z(pOther.z) {}
	Vec3f Vec3f::operator=(const Vec3f& pOther) { x = pOther.x; y = pOther.y; z = pOther.z; return *this; }

	const Vec3f Vec3f::Zero(0.f, 0.f, 0.f);
	const Vec3f Vec3f::One(1.f, 1.f, 1.f);
	const Vec3f Vec3f::Up(0.f, 1.f, 0.f);
	const Vec3f Vec3f::Down(0.f, -1.f, 0.f);
	const Vec3f Vec3f::Left(-1.f, 0.f, 0.f);
	const Vec3f Vec3f::Right(1.f, 0.f, 0.f);
	const Vec3f Vec3f::Forward(0.f, 0.f, 1.f);
	const Vec3f Vec3f::Backward(0.f, 0.f, -1.f);

	Vec3f Vec3f::operator+(const Vec3f& pOther) const { return Vec3f(x + pOther.x, y + pOther.y, z + pOther.z); }
	Vec3f Vec3f::operator-(const Vec3f& pOther) const { return Vec3f(x - pOther.x, y - pOther.y, z - pOther.z); }
	Vec3f Vec3f::operator*(const Vec3f& pOther) const { return Vec3f(x * pOther.x, y * pOther.y, z * pOther.z); }
	Vec3f Vec3f::operator/(const Vec3f& pOther) const
	{
		if (pOther.x == 0 || pOther.y == 0 || pOther.z == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec3f(x / pOther.x, y / pOther.y, z / pOther.z);
	}

	Vec3f Vec3f::operator+(float pOther) const { return Vec3f(x + pOther, y + pOther, z + pOther); }
	Vec3f Vec3f::operator-(float pOther) const { return Vec3f(x - pOther, y - pOther, z - pOther); }
	Vec3f Vec3f::operator*(float pOther) const { return Vec3f(x * pOther, y * pOther, z * pOther); }
	Vec3f Vec3f::operator/(float pOther) const
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec3f(x / pOther, y / pOther, z / pOther);
	}

	Vec3f& Vec3f::operator+=(const Vec3f& pOther) { x += pOther.x; y += pOther.y; z += pOther.z; return *this; }
	Vec3f& Vec3f::operator-=(const Vec3f& pOther) { x -= pOther.x; y -= pOther.y; z -= pOther.z; return *this; }
	Vec3f& Vec3f::operator*=(const Vec3f& pOther) { x *= pOther.x; y *= pOther.y; z *= pOther.z; return *this; }
	Vec3f& Vec3f::operator/=(const Vec3f& pOther)
	{
		if (pOther.x == 0 || pOther.y == 0 || pOther.z == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther.x;
		y /= pOther.y;
		z /= pOther.z;

		return *this;
	}

	Vec3f& Vec3f::operator+=(float pOther) { x += pOther; y += pOther; z += pOther; return *this; }
	Vec3f& Vec3f::operator-=(float pOther) { x -= pOther; y -= pOther; z -= pOther; return *this; }
	Vec3f& Vec3f::operator*=(float pOther) { x *= pOther; y *= pOther; z *= pOther; return *this; }
	Vec3f& Vec3f::operator/=(float pOther)
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther;
		y /= pOther;
		z /= pOther;

		return *this;
	}

	bool Vec3f::operator==(const Vec3f& pOther) const { return x == pOther.x && y == pOther.y && z == pOther.z; }
	bool Vec3f::operator!=(const Vec3f& pOther) const { return x != pOther.x || y != pOther.y || z != pOther.z; }

	std::ostream& operator<<(std::ostream& pStream, const Vec3f& pVec)
	{
		pStream << "Vec3f(" << pVec.x << ", " << pVec.y << ", " << pVec.z << ")";
		return pStream;
	}

	std::string Vec3f::ToString() const
	{
		return "Vec3f(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}

	float Vec3f::sqrMagnitude(const Vec3f& pVec)
	{
		return (pVec.x * pVec.x) + (pVec.y * pVec.y) + (pVec.z * pVec.z);
	}

	float Vec3f::Magnitude(const Vec3f& pVec)
	{
		return sqrt(sqrMagnitude(pVec));
	}

	float Vec3f::Dot(const Vec3f& pVec1, const Vec3f& pVec2)
	{
		return (pVec1.x * pVec2.x) + (pVec1.y * pVec2.y) + (pVec1.z * pVec2.z);
	}

	float Vec3f::sqrDistance(const Vec3f& pVec1, const Vec3f& pVec2)
	{
		return sqrMagnitude(pVec1 - pVec2);
	}

	float Vec3f::Distance(const Vec3f& pVec1, const Vec3f& pVec2)
	{
		return Magnitude(pVec1 - pVec2);
	}

	float Vec3f::Angle(const Vec3f& pVec1, const Vec3f& pVec2)
	{
		return acos(Dot(pVec1, pVec2) / (Magnitude(pVec1) * Magnitude(pVec2)));
	}

	Vec3f Vec3f::Normalize(const Vec3f& pVec)
	{
		return pVec / Magnitude(pVec);
	}

	Vec3f Vec3f::Lerp(const Vec3f& pStart, const Vec3f& pEnd, float pDelta)
	{
		return pStart + (pEnd - pStart) * pDelta;
	}

	Vec3f Vec3f::Cross(const Vec3f& pLeft, const Vec3f& pRight)
	{
		return Vec3f
		(
			(pLeft.y * pRight.z) - (pLeft.z * pRight.y),
			(pLeft.z * pRight.x) - (pLeft.x * pRight.z),
			(pLeft.x * pRight.y) - (pLeft.y * pRight.x)
		);
	}

	Vec3f Vec3f::Project(const Vec3f& pVec, const Vec3f& pOnNormal)
	{
		float aDotb = Dot(pVec, pOnNormal);
		float bDotb = Dot(pOnNormal, pOnNormal);

		if (bDotb == 0.0f) return Vec3f::Zero;

		return pOnNormal * (aDotb / bDotb);
	}

	Vec3f Vec3f::Reflect(const Vec3f& pVec, const Vec3f& pNormal)
	{
		return pVec - (pNormal * (2.0f * Dot(pVec, pNormal)));
	}

	float Vec3f::sqrMagnitude()
	{
		return sqrMagnitude(*this);
	}

	float Vec3f::Magnitude()
	{
		return Magnitude(*this);
	}

	float Vec3f::Dot(const Vec3f& pRight)
	{
		return Dot(*this, pRight);
	}

	float Vec3f::sqrDistance(const Vec3f& pRight)
	{
		return sqrDistance(*this, pRight);
	}

	float Vec3f::Distance(const Vec3f& pRight)
	{
		return Distance(*this, pRight);
	}

	float Vec3f::Angle(const Vec3f& pRight)
	{
		return Angle(*this, pRight);
	}

	void Vec3f::Normalize()
	{
		*this = Normalize(*this);
	}

	void Vec3f::Lerp(const Vec3f& pEnd, float pDelta)
	{
		*this = Lerp(*this, pEnd, pDelta);
	}

	void Vec3f::Cross(const Vec3f& pRight)
	{
		*this = Cross(*this, pRight);
	}

	void Vec3f::Project(const Vec3f& pOnNormal)
	{
		*this = Project(*this, pOnNormal);
	}

	void Vec3f::Reflect(const Vec3f& pNormal)
	{
		*this = Reflect(*this, pNormal);
	}
}