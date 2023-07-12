#include "Vec2.hpp"
#include <cmath>

#include <stdexcept>
#include <string>

namespace MGLMaths
{
	Vec2f::Vec2f(float pX, float pY) : x(pX), y(pY) {}
	Vec2f::Vec2f(float pX) : x(pX), y(pX) {}
	Vec2f::Vec2f() : x(0), y(0) {}
	Vec2f::Vec2f(const Vec2f& pOther) : x(pOther.x), y(pOther.y) {}
	Vec2f Vec2f::operator=(const Vec2f& pOther) { x = pOther.x; y = pOther.y; return *this; }

	const Vec2f Vec2f::Zero(0.f, 0.f);
	const Vec2f Vec2f::One(1.f, 1.f);

	Vec2f Vec2f::operator+(const Vec2f& pOther) const { return Vec2f(x + pOther.x, y + pOther.y); }
	Vec2f Vec2f::operator-(const Vec2f& pOther) const { return Vec2f(x - pOther.x, y - pOther.y); }
	Vec2f Vec2f::operator*(const Vec2f& pOther) const { return Vec2f(x * pOther.x, y * pOther.y); }
	Vec2f Vec2f::operator/(const Vec2f& pOther) const
	{
		if (pOther.x == 0 || pOther.y == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec2f(x / pOther.x, y / pOther.y);
	}

	Vec2f Vec2f::operator+(float pOther) const { return Vec2f(x + pOther, y + pOther); }
	Vec2f Vec2f::operator-(float pOther) const { return Vec2f(x - pOther, y - pOther); }
	Vec2f Vec2f::operator*(float pOther) const { return Vec2f(x * pOther, y * pOther); }
	Vec2f Vec2f::operator/(float pOther) const
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		return Vec2f(x / pOther, y / pOther);
	}

	Vec2f& Vec2f::operator+=(const Vec2f& pOther) { x += pOther.x; y += pOther.y; return *this; }
	Vec2f& Vec2f::operator-=(const Vec2f& pOther) { x -= pOther.x; y -= pOther.y; return *this; }
	Vec2f& Vec2f::operator*=(const Vec2f& pOther) { x *= pOther.x; y *= pOther.y; return *this; }
	Vec2f& Vec2f::operator/=(const Vec2f& pOther)
	{
		if (pOther.x == 0 || pOther.y == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther.x;
		y /= pOther.y;

		return *this;
	}

	Vec2f& Vec2f::operator+=(float pOther) { x += pOther; y += pOther; return *this; }
	Vec2f& Vec2f::operator-=(float pOther) { x -= pOther; y -= pOther; return *this; }
	Vec2f& Vec2f::operator*=(float pOther) { x *= pOther; y *= pOther; return *this; }
	Vec2f& Vec2f::operator/=(float pOther)
	{
		if (pOther == 0)
			throw std::logic_error("Divide by zero exception");

		x /= pOther;
		y /= pOther;

		return *this;
	}

	bool Vec2f::operator==(const Vec2f& pOther) const { return x == pOther.x && y == pOther.y; }
	bool Vec2f::operator!=(const Vec2f& pOther) const { return x != pOther.x || y != pOther.y; }

	std::string Vec2f::ToString() const
	{
		return "Vec2f(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	float Vec2f::sqrMagnitude(const Vec2f& pVec) // sqrMagnitude == sqrLength
	{
		return (pVec.x * pVec.x) + (pVec.y * pVec.y);
	}

	float Vec2f::Magnitude(const Vec2f& pVec) // Magnitude == Length
	{
		return std::sqrt(sqrMagnitude(pVec));
	}

	float Vec2f::Dot(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return (pLeft.x * pRight.x) + (pLeft.y * pRight.y);
	}

	float Vec2f::sqrDistance(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return sqrMagnitude(pLeft - pRight);
	}

	float Vec2f::Distance(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return Magnitude(pLeft - pRight);
	}

	float Vec2f::Angle(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return std::acos(Dot(pLeft, pRight) / (Magnitude(pLeft) * Magnitude(pRight)));
	}

	Vec2f Vec2f::Normalize(const Vec2f& pVec)
	{
		return pVec / Magnitude(pVec);
	}

	Vec2f Vec2f::Lerp(const Vec2f& pLeft, const Vec2f& pRight, float pTime)
	{
		return pLeft + (pRight - pLeft) * pTime;
	}

	Vec2f Vec2f::Min(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return Vec2f(std::min(pLeft.x, pRight.x), std::min(pLeft.y, pRight.y));
	}

	Vec2f Vec2f::Max(const Vec2f& pLeft, const Vec2f& pRight)
	{
		return Vec2f(std::max(pLeft.x, pRight.x), std::max(pLeft.y, pRight.y));
	}

	float Vec2f::sqrMagnitude()
	{
		return sqrMagnitude(*this);
	}

	float Vec2f::Magnitude()
	{
		return Magnitude(*this);
	}

	float Vec2f::Dot(const Vec2f& pOther)
	{
		return Dot(*this, pOther);
	}

	float Vec2f::sqrDistance(const Vec2f& pOther)
	{
		return sqrDistance(*this, pOther);
	}

	float Vec2f::Distance(const Vec2f& pOther)
	{
		return Distance(*this, pOther);
	}

	float Vec2f::Angle(const Vec2f& pOther)
	{
		return Angle(*this, pOther);
	}

	void Vec2f::Normalize()
	{
		*this /= Magnitude(*this);
	}

	void Vec2f::Lerp(const Vec2f& pOther, float pTime)
	{
		*this += (pOther - *this) * pTime;
	}

	void Vec2f::Min(const Vec2f& pOther)
	{
		x = std::min(x, pOther.x);
		y = std::min(y, pOther.y);
	}

	void Vec2f::Max(const Vec2f& pOther)
	{
		x = std::max(x, pOther.x);
		y = std::max(y, pOther.y);
	}
}