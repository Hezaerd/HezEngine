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

    float Vec3f::operator[](int pIndex) const
    {
        if (pIndex < 0 || pIndex > 2)
            throw std::out_of_range("Invalid index : " + std::to_string(pIndex) + "is out of range.");

        if (pIndex == 0) return x;
        if (pIndex == 1) return y;
        return z;
    }

    float& Vec3f::operator[](int pIndex)
    {
        if (pIndex < 0 || pIndex > 2)
            throw std::out_of_range("Invalid index : " + std::to_string(pIndex) + "is out of range.");

        if (pIndex == 0) return x;
        if (pIndex == 1) return y;
        return z;
    }

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

    const float* Vec3f::GetPointer() const
    {
        return &x;
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
}