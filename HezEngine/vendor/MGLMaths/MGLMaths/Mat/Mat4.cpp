#include "Mat4.hpp"
#include <cmath>

#include <sstream>
#include <stdexcept>
#include <string>
#include "Utils.hpp"

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
		*this = Mat4f(1.f);
	}

	Mat4f::Mat4f(const Mat4f& pOther)
	{
		memcpy(data, pOther.data, 4 * sizeof(Vec4f));
	}

	Mat4f Mat4f::operator=(const Mat4f& pOther)
	{
		memcpy(data, pOther.data, 4 * sizeof(Vec4f));
		return *this;
	}

	const Mat4f Mat4f::Identity(1.f);

	float& Mat4f::operator()(uint8_t pRow, uint8_t pCollumn)
	{
		if (pRow < 0 || pRow > 3 || pCollumn < 0 || pCollumn > 3)
			throw std::out_of_range("Index out of range : (" + std::to_string(pRow) + ", " + std::to_string(pCollumn) + ").");
		return data[pRow][pCollumn];
	}

	float Mat4f::operator()(uint8_t pRow, uint8_t pCollumn) const
	{
		if (pRow < 0 || pRow > 3 || pCollumn < 0 || pCollumn > 3)
			throw std::out_of_range("Index out of range : (" + std::to_string(pRow) + ", " + std::to_string(pCollumn) + ").");
		return data[pRow][pCollumn];
	}

	Vec4f& Mat4f::operator()(uint8_t pRow)
	{
		if (pRow < 0 || pRow > 3)
			throw std::out_of_range("Index out of range : (" + std::to_string(pRow) + ").");
		return data[pRow];
	}

	Vec4f Mat4f::operator()(uint8_t pRow) const
	{
		if (pRow < 0 || pRow > 3)
			throw std::out_of_range("Index out of range : (" + std::to_string(pRow) + ").");
		return data[pRow];
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
			for (uint8_t j = 0; j < 4; j++)
			{
				result.data[i][j] =
					data[i][0] * pOther.data[0][j]
					+ data[i][1] * pOther.data[1][j]
					+ data[i][2] * pOther.data[2][j]
					+ data[i][3] * pOther.data[3][j];
			}
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
				data[i][j] =
					data[i][0] * pOther.data[0][j]
					+ data[i][1] * pOther.data[1][j]
					+ data[i][2] * pOther.data[2][j]
					+ data[i][3] * pOther.data[3][j];
			}
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

	std::string Mat4f::ToString() const
	{
		std::string result = "Mat4f(";
		for (uint8_t i = 0; i < 4; i++)
		{
			result += data[i].ToString();
			if (i != 3)
				result += ", ";
		}
		result += ")";
		return result;
	}

	Mat4f Mat4f::Rotate(const Mat4f& pMatrix, const Vec3f& pRotation)
	{
		if (pRotation == Vec3f(0.0f, 0.0f, 0.0f))
			return pMatrix;
		Mat4f result(pMatrix);

		//use ZXY rotation order
		const float Radx = (float)toRadians(pRotation.x);
		const float Rady = (float)toRadians(pRotation.y);
		const float Radz = (float)toRadians(pRotation.z);
		//Z rotation mat

		Mat4f zRotMat;
		zRotMat(0, 0) = cos(Radz);
		zRotMat(0, 1) = -sin(Radz);
		zRotMat(1, 0) = sin(Radz);
		zRotMat(1, 1) = cos(Radz);

		result *= zRotMat;

		//X rotation mat
		Mat4f xRotMat;

		xRotMat(1, 1) = cos(Radx);
		xRotMat(1, 2) = -sin(Radx);
		xRotMat(2, 1) = sin(Radx);
		xRotMat(2, 2) = cos(Radx);

		result *= xRotMat;

		//Y rotation mat
		Mat4f yRotMat;

		yRotMat(0, 0) = cos(Rady);
		yRotMat(0, 2) = sin(Rady);
		yRotMat(2, 0) = -sin(Rady);
		yRotMat(2, 2) = cos(Rady);

		result *= yRotMat;

		return result;
	}

	Mat4f Mat4f::Scale(const Mat4f& pMatrix, const Vec3f& pScale)
	{
		Mat4f result(pMatrix);

		result(0, 0) *= pScale.x;
		result(1, 1) *= pScale.y;
		result(2, 2) *= pScale.z;

		return result;
	}

	Mat4f Mat4f::Translate(const Mat4f& pMatrix, const Vec3f& pTranslate)
	{
		Mat4f result(pMatrix);

		result(3, 0) += pTranslate.x;
		result(3, 1) += pTranslate.y;
		result(3, 2) += pTranslate.z;

		return result;
	}

	const float* Mat4f::GetPointer() const
	{
		return &data[0].x;
	}

	Mat4f Mat4f::Transform(const Vec3f& pPosition, const Vec3f& pRotation, const Vec3f& pScale)
	{
		Mat4f result;

		result = Translate(result, pPosition);
		result = Rotate(result, pRotation);
		result = Scale(result, pScale);

		return result;
	}

	Mat4f Mat4f::Inverse(const Mat4f& pMatrix)
	{
		float Coef00 = pMatrix(2, 2) * pMatrix(3, 3) - pMatrix(3, 2) * pMatrix(2, 3);
		float Coef02 = pMatrix(1, 2) * pMatrix(3, 3) - pMatrix(3, 2) * pMatrix(1, 3);
		float Coef03 = pMatrix(1, 2) * pMatrix(2, 3) - pMatrix(2, 2) * pMatrix(1, 3);

		float Coef04 = pMatrix(2, 1) * pMatrix(3, 3) - pMatrix(3, 1) * pMatrix(2, 3);
		float Coef06 = pMatrix(1, 1) * pMatrix(3, 3) - pMatrix(3, 1) * pMatrix(1, 3);
		float Coef07 = pMatrix(1, 1) * pMatrix(2, 3) - pMatrix(2, 1) * pMatrix(1, 3);

		float Coef08 = pMatrix(2, 1) * pMatrix(3, 2) - pMatrix(3, 1) * pMatrix(2, 2);
		float Coef10 = pMatrix(1, 1) * pMatrix(3, 2) - pMatrix(3, 1) * pMatrix(1, 2);
		float Coef11 = pMatrix(1, 1) * pMatrix(2, 2) - pMatrix(2, 1) * pMatrix(1, 2);

		float Coef12 = pMatrix(2, 0) * pMatrix(3, 3) - pMatrix(3, 0) * pMatrix(2, 3);
		float Coef14 = pMatrix(1, 0) * pMatrix(3, 3) - pMatrix(3, 0) * pMatrix(1, 3);
		float Coef15 = pMatrix(1, 0) * pMatrix(2, 3) - pMatrix(2, 0) * pMatrix(1, 3);

		float Coef16 = pMatrix(2, 0) * pMatrix(3, 2) - pMatrix(3, 0) * pMatrix(2, 2);
		float Coef18 = pMatrix(1, 0) * pMatrix(3, 2) - pMatrix(3, 0) * pMatrix(1, 2);
		float Coef19 = pMatrix(1, 0) * pMatrix(2, 2) - pMatrix(2, 0) * pMatrix(1, 2);

		float Coef20 = pMatrix(2, 0) * pMatrix(3, 1) - pMatrix(3, 0) * pMatrix(2, 1);
		float Coef22 = pMatrix(1, 0) * pMatrix(3, 1) - pMatrix(3, 0) * pMatrix(1, 1);
		float Coef23 = pMatrix(1, 0) * pMatrix(2, 1) - pMatrix(2, 0) * pMatrix(1, 1);

		Vec4f Fac0(Coef00, Coef00, Coef02, Coef03);
		Vec4f Fac1(Coef04, Coef04, Coef06, Coef07);
		Vec4f Fac2(Coef08, Coef08, Coef10, Coef11);
		Vec4f Fac3(Coef12, Coef12, Coef14, Coef15);
		Vec4f Fac4(Coef16, Coef16, Coef18, Coef19);
		Vec4f Fac5(Coef20, Coef20, Coef22, Coef23);

		Vec4f Vec0(pMatrix(1, 0), pMatrix(0, 0), pMatrix(0, 0), pMatrix(0, 0));
		Vec4f Vec1(pMatrix(1, 1), pMatrix(0, 1), pMatrix(0, 1), pMatrix(0, 1));
		Vec4f Vec2(pMatrix(1, 2), pMatrix(0, 2), pMatrix(0, 2), pMatrix(0, 2));
		Vec4f Vec3(pMatrix(1, 3), pMatrix(0, 3), pMatrix(0, 3), pMatrix(0, 3));

		Vec4f Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
		Vec4f Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
		Vec4f Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
		Vec4f Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

		Vec4f SignA(+1, -1, +1, -1);
		Vec4f SignB(-1, +1, -1, +1);

		Mat4f Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

		Vec4f Row0(Inverse(0, 0), Inverse(1, 0), Inverse(2, 0), Inverse(3, 0));

		Vec4f Dot0(pMatrix(0) * Row0);
		float Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

		float OneOverDeterminant = 1.0f / Dot1;

		return Inverse * OneOverDeterminant;
	}

	Mat4f Mat4f::Transpose(const Mat4f& pMatrix)
	{
		Mat4f result;

		for (uint8_t i = 0; i < 4; ++i)
		{
			result(i, 0) = pMatrix(0, i);
			result(i, 1) = pMatrix(1, i);
			result(i, 2) = pMatrix(2, i);
			result(i, 3) = pMatrix(3, i);
		}

		return result;
	}

	void Mat4f::Transpose()
	{
		*this = Transpose(*this);
	}

	Mat4f Mat4f::LookAt(const Vec3f& pPosition, const Vec3f& pTarget, const Vec3f& pUp)
	{
		const Vec3f  front = Vec3f::Normalize(pTarget - pPosition);
		const Vec3f  right = Vec3f::Normalize(Vec3f::Cross(front, pUp));
		const Vec3f  up = Vec3f::Cross(right, front);

		Mat4f result;

		result(0, 0) = right.x;
		result(1, 0) = right.y;
		result(2, 0) = right.z;
		result(0, 1) = up.x;
		result(1, 1) = up.y;
		result(2, 1) = up.z;
		result(0, 2) = -front.x;
		result(1, 2) = -front.y;
		result(2, 2) = -front.z;
		result(3, 0) = -Vec3f::Dot(right, pPosition);
		result(3, 1) = -Vec3f::Dot(up, pPosition);
		result(3, 2) = Vec3f::Dot(front, pPosition);

		return result;
	}

	Mat4f Mat4f::Perspective(float pFov, float pAspect, float pNear, float pFar)
	{
		Mat4f result;

		float scale = tan(pFov * PI / 360) * pNear;
		float r = pAspect * scale;
		float l = -r;
		float t = scale;
		float b = -t;
		float x1 = (2 * pNear) / (r - l);
		float y2 = (2 * pNear) / (t - b);
		float x3 = (r + l) / (r - l);
		float y3 = (t + b) / (t - b);
		float z3 = -(pFar + pNear) / (pFar - pNear);
		float z4 = -(2 * pFar * pNear) / (pFar - pNear);

		result(0, 0) = x1;
		result(1, 1) = y2;
		result(2, 0) = x3;
		result(2, 1) = y3;
		result(2, 2) = z3;
		result(2, 3) = -1;
		result(3, 2) = z4;

		return result;
	}

	void Mat4f::Rotate(const Vec3f& pRotation)
	{
		*this = Rotate(*this, pRotation);
	}

	void Mat4f::Scale(const Vec3f& pScale)
	{
		*this = Scale(*this, pScale);
	}

	void Mat4f::Translate(const Vec3f& pTranslate)
	{
		*this = Translate(*this, pTranslate);
	}

	void Mat4f::Inverse()
	{
		*this = Inverse(*this);
	}
}