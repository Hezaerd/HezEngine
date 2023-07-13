#pragma once

#include <ostream>

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
        Vec3f(Vec3f&& pOther) noexcept = default;
        Vec3f operator=(const Vec3f& pOther);
        Vec3f& operator=(Vec3f&& pOther) noexcept = default;

        static const Vec3f Zero;
        static const Vec3f One;
        static const Vec3f Up;
        static const Vec3f Down;
        static const Vec3f Left;
        static const Vec3f Right;
        static const Vec3f Forward;
        static const Vec3f Backward;

        float operator[](int pIndex) const;
        float& operator[](int pIndex);

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

        float sqrMagnitude();
        float Magnitude();
        float Dot(const Vec3f& pRight);
        float sqrDistance(const Vec3f& pRight);
        float Distance(const Vec3f& pRight);
        float Angle(const Vec3f& pRight);

        void Normalize();
        void Lerp(const Vec3f& pEnd, float pDelta);
        void Cross(const Vec3f& pRight);

        const float* GetPointer() const;
    };
}