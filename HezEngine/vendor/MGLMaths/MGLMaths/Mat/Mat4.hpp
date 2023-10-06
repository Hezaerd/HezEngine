#pragma once

#include "../Vec/Vec4.hpp"
#include "../Vec/Vec3.hpp"

#include <ostream>

namespace MGLMaths
{
    class Mat4f
    {
    public:
        Vec4f data[4];

    public:
        Mat4f(const Vec4f& pRow0, const Vec4f& pRow1, const Vec4f& pRow2, const Vec4f& pRow3);
        Mat4f(float pDiagonal);
        Mat4f();
        Mat4f(const Mat4f& pOther);
        Mat4f(Mat4f&& pOther) noexcept = default;
        Mat4f operator=(const Mat4f& pOther);
        Mat4f& operator=(Mat4f&& pOther) noexcept = default;

        static const Mat4f Identity;

        float& operator()(uint8_t pRow, uint8_t pCollumn);
        float operator()(uint8_t pRow, uint8_t pCollumn) const;

        Vec4f& operator()(uint8_t pRow);
        Vec4f operator()(uint8_t pRow) const;

        Mat4f operator+(const Mat4f& pOther) const;
        Mat4f operator-(const Mat4f& pOther) const;
        Mat4f operator*(const Mat4f& pOther) const;

        Mat4f operator+(float pOther) const;
        Mat4f operator-(float pOther) const;
        Mat4f operator*(float pOther) const;

        Mat4f& operator+=(const Mat4f& pOther);
        Mat4f& operator-=(const Mat4f& pOther);
        Mat4f& operator*=(const Mat4f& pOther);

        Mat4f& operator+=(float pOther);
        Mat4f& operator-=(float pOther);
        Mat4f& operator*=(float pOther);

        bool operator==(const Mat4f& pOther) const;
        bool operator!=(const Mat4f& pOther) const;

        std::string ToString() const;

        static Mat4f Rotate(const Mat4f& pMatrix, const Vec3f& pRotation);
        static Mat4f Scale(const Mat4f& pMatrix, const Vec3f& pScale);
        static Mat4f Translate(const Mat4f& pMatrix, const Vec3f& pTranslate);
        static Mat4f Transform(const Vec3f& pPosition, const Vec3f& pRotation, const Vec3f& pScale);
        static Mat4f Inverse(const Mat4f& pMatrix);
        static Mat4f Transpose(const Mat4f& pMatrix);

        static Mat4f LookAt(const Vec3f& pPosition, const Vec3f& pTarget, const Vec3f& pUp);
        static Mat4f Perspective(float pFov, float pAspect, float pNear, float pFar);

        void Rotate(const Vec3f& pRotation);
        void Scale(const Vec3f& pScale);
        void Translate(const Vec3f& pTranslate);
        void Inverse();
        void Transpose();

        const float* GetPointer() const;
    };
}