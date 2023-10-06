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

    float Vec4f::operator[](int pIndex) const
    {
        if (pIndex < 0 || pIndex > 3)
            throw std::out_of_range("Invalid index : " + std::to_string(pIndex) + "is out of range.");

        if (pIndex == 0) return x;
        if (pIndex == 1) return y;
        if (pIndex == 2) return z;
        return w;
    }

    float& Vec4f::operator[](int pIndex)
    {
        if (pIndex < 0 || pIndex > 3)
            throw std::out_of_range("Invalid index : " + std::to_string(pIndex) + "is out of range.");

        if (pIndex == 0) return x;
        if (pIndex == 1) return y;
        if (pIndex == 2) return z;
        return w;
    }

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

    Vec4f Vec4f::NLerp(const Vec4f& pLeft, const Vec4f& pRight, float pTime)
    {
        return Normalize(Lerp(pLeft, pRight, pTime));
    }

    const float* Vec4f::GetPointer() const
    {
        return &x;
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

    Vec4f Vec4f::NLerp(const Vec4f& pOther, float pTime)
    {
        return NLerp(*this, pOther, pTime);
    }
}