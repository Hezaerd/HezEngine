#include "Mat3.hpp"
#include "Mat4.hpp"

namespace MGLMaths
{
    Mat3f::Mat3f()
    {
        data[0] = Vec3f(1.0f, 0.0f, 0.0f);
        data[1] = Vec3f(0.0f, 1.0f, 0.0f);
        data[2] = Vec3f(0.0f, 0.0f, 1.0f);
    }

    Mat3f::Mat3f(float pDiagonal)
    {
        data[0] = Vec3f(pDiagonal, 0.0f, 0.0f);
        data[1] = Vec3f(0.0f, pDiagonal, 0.0f);
        data[2] = Vec3f(0.0f, 0.0f, pDiagonal);
    }

    Mat3f::Mat3f(const Mat3f& pOther)
    {
        data[0] = pOther.data[0];
        data[1] = pOther.data[1];
        data[2] = pOther.data[2];
    }

    Mat3f::Mat3f(Mat3f&& pOther) noexcept
    {
        data[0] = std::move(pOther.data[0]);
        data[1] = std::move(pOther.data[1]);
        data[2] = std::move(pOther.data[2]);
    }

    Mat3f& Mat3f::operator=(const Mat3f& pOther)
    {
        data[0] = pOther.data[0];
        data[1] = pOther.data[1];
        data[2] = pOther.data[2];

        return *this;
    }

    Mat3f& Mat3f::operator=(const Mat4f& pOther)
    {
        data[0] = Vec3f(pOther.data[0].x, pOther.data[0].y, pOther.data[0].z);
        data[1] = Vec3f(pOther.data[1].x, pOther.data[1].y, pOther.data[1].z);
        data[2] = Vec3f(pOther.data[2].x, pOther.data[2].y, pOther.data[2].z);

        return *this;
    }

    Mat3f& Mat3f::operator=(Mat3f&& pOther) noexcept
    {
        data[0] = std::move(pOther.data[0]);
        data[1] = std::move(pOther.data[1]);
        data[2] = std::move(pOther.data[2]);

        return *this;
    }

    Mat3f& Mat3f::Multiply(const Mat3f& pOther)
    {
        Mat3f result;
        for (uint8_t i = 0; i < 3; i++)
        {
            Vec3f vec3;
            for (uint8_t j = 0; j < 3; j++)
            {
                vec3[j] = data[0][j] * pOther.data[i].x
                    + data[0][j] * pOther.data[i].y
                    + data[0][j] * pOther.data[i].z;
            }
            result.data[i] = vec3;
        }
        return result;
    }

    const float* Mat3f::GetPointer() const
    {
        return &data[0].x;
    }

    Mat3f Mat3f::Identity()
    {
        Mat3f result;
        result.data[0] = Vec3f(1, 0, 0);
        result.data[1] = Vec3f(0, 1, 0);
        result.data[2] = Vec3f(0, 0, 1);
        return result;
    }

    Mat3f& Mat3f::operator*=(const Mat3f& pOther)
    {
        return Multiply(pOther);
    }

    Mat3f& Mat3f::operator*(const Mat3f& pOther)
    {
        return Multiply(pOther);
    }
}