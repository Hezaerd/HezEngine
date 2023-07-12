#include "Mat4.hpp"
#include <cmath>

#include <sstream>
#include <stdexcept>
#include <string>

namespace MGLMaths
{
	Mat4f::Mat4f(const Vec4f& pRow0, const Vec4f& pRow1, const Vec4f& pRow2, const Vec4f& pRow3)
	{
		data[0] = pRow0;
		data[1] = pRow1;
		data[2] = pRow2;
		data[3] = pRow3;
	}

	Mat4f::Mat4f(float pDiagonal)
	{
		data[0] = Vec4f(pDiagonal, 0.f, 0.f, 0.f);
		data[1] = Vec4f(0.f, pDiagonal, 0.f, 0.f);
		data[2] = Vec4f(0.f, 0.f, pDiagonal, 0.f);
		data[3] = Vec4f(0.f, 0.f, 0.f, pDiagonal);
	}

	Mat4f::Mat4f()
	{
		Mat4f(1.f);
	}

	Mat4f::Mat4f(const Mat4f& pOther)
	{
		*this = pOther;
	}

	Mat4f Mat4f::operator=(const Mat4f& pOther)
	{
		memcpy(data, pOther.data, 4 * sizeof(Vec4f));
		return *this;
	}

	const Mat4f Mat4f::Idendity(1.f);

	float& Mat4f::operator()(uint8_t pRow, uint8_t pCollumn)
	{
		if (pRow < 0 || pRow > 4 || pCollumn < 0 || pCollumn > 4)
			throw std::out_of_range("Index out of range : (" + std::to_string(pRow) + ", " + std::to_string(pCollumn) + ").");
		return data[pRow][pCollumn];
	}

	Mat4f Mat4f::operator+(const Mat4f& pOther) const
	{
		Mat4f result(*this);
		for (uint8_t i = 0; i < 4; i++)
			result.data[i] += pOther.data[i];
		return result;
	}

	Mat4f Mat4f::operator-(const Mat4f& pOther) const
	{
		Mat4f result(*this);
		for (uint8_t i = 0; i < 4; i++)
			result.data[i] -= pOther.data[i];
		return result;
	}

	Mat4f Mat4f::operator*(const Mat4f& pOther) const
	{
		Mat4f result;
		for (uint8_t i = 0; i < 4; i++)
		{
			Vec4f vec4;
			for (uint8_t j = 0; j < 4; j++)
			{
				vec4[j] = data[0][j] * pOther.data[i].x
					+ data[0][j] * pOther.data[i].y
					+ data[0][j] * pOther.data[i].z
					+ data[0][j] * pOther.data[i].w;
			}
			result.data[i] = vec4;
		}
		return result;
	}

	Mat4f Mat4f::operator+(float pOther) const
	{
		Mat4f result(*this);
		for (uint8_t i = 0; i < 4; i++)
			result.data[i] += pOther;
		return result;
	}

	Mat4f Mat4f::operator-(float pOther) const
	{
		Mat4f result(*this);
		for (uint8_t i = 0; i < 4; i++)
			result.data[i] -= pOther;
		return result;
	}

	Mat4f Mat4f::operator*(float pOther) const
	{
		Mat4f result(*this);
		for (uint8_t i = 0; i < 4; i++)
			result.data[i] *= pOther;
		return result;
	}

	Mat4f& Mat4f::operator+=(const Mat4f& pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
			data[i] += pOther.data[i];
		return *this;
	}

	Mat4f& Mat4f::operator-=(const Mat4f& pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
			data[i] -= pOther.data[i];
		return *this;
	}

	Mat4f& Mat4f::operator*=(const Mat4f& pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
		{
			Vec4f vec4;
			for (uint8_t j = 0; j < 4; j++)
			{
				vec4[j] = data[0][j] * pOther.data[i].x
					+ data[0][j] * pOther.data[i].y
					+ data[0][j] * pOther.data[i].z
					+ data[0][j] * pOther.data[i].w;
			}
			data[i] = vec4;
		}
		return *this;
	}

	Mat4f& Mat4f::operator+=(float pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
			data[i] += pOther;
		return *this;
	}

	Mat4f& Mat4f::operator-=(float pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
			data[i] -= pOther;
		return *this;
	}

	Mat4f& Mat4f::operator*=(float pOther)
	{
		for (uint8_t i = 0; i < 4; i++)
			data[i] *= pOther;
		return *this;
	}

	bool Mat4f::operator==(const Mat4f& pOther) const
	{
		return memcmp(&data, &pOther.data, 4 * sizeof(Vec4f)) == 0;
	}

	bool Mat4f::operator!=(const Mat4f& pOther) const
	{
		return memcmp(&data, &pOther.data, 4 * sizeof(Vec4f)) != 0;
	}

	//std::string Mat4f::ToString() const
	//{
	//	std::stringstream ss;
	//	ss << *this;
	//	return ss.str();
	//}

	/*Mat4f Mat4f::Rotate(const Mat4f& pMatrix, const Vec3f& pRotation)
	{
	}

	Mat4f Mat4f::Scale(const Mat4f& pMatrix, const Vec3f& pScale)
	{
	}

	Mat4f Mat4f::Translate(const Mat4f& pMatrix, const Vec3f& pTranslate)
	{
	}

	Mat4f Mat4f::Transform(const Vec3f& pPosition, const Vec3f& pRotation, const Vec3f& pScale)
	{
	}

	Mat4f Mat4f::LookAt(const Vec3f& pPosition, const Vec3f& pTarget, const Vec3f& pUp)
	{
	}

	Mat4f Mat4f::Perspective(float pFov, float pAspect, float pNear, float pFar)
	{
	}

	void Mat4f::Rotate(const Vec3f& pRotation)
	{
	}

	void Mat4f::Scale(const Vec3f& pScale)
	{
	}

	void Mat4f::Translate(const Vec3f& pTranslate)
	{
	}*/
}