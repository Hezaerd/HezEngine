#pragma once
#include "../Vec/Vec3.hpp"

namespace MGLMaths
{
    class Mat4f;
    class Mat3f
    {
    public:
        Vec3f data[3];

    public:
        Mat3f();
        Mat3f(float pDiagonal);
        Mat3f(const Mat3f& pOther);
        Mat3f(Mat3f&& pOther) noexcept;
        ~Mat3f() = default;

        Mat3f& operator=(const Mat3f& pOther);
        Mat3f& operator=(const Mat4f& pOther);
        Mat3f& operator=(Mat3f&& pOther) noexcept;

        Mat3f& Multiply(const Mat3f& pOther);
        Mat3f& operator*(const Mat3f& pOther);
        Mat3f& operator*=(const Mat3f& pOther);

        const float* GetPointer() const;

        static Mat3f Identity();
    };
}