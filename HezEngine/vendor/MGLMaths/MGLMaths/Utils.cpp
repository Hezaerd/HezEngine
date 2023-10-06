#include "Utils.hpp"

#include <random>

namespace MGLMaths
{
	const double toRadians(const double& pDegrees)
	{
		return pDegrees * (PI / HALF_CIRCLE);
	}

	const double toDegrees(const double& pRadians)
	{
		return pRadians * (HALF_CIRCLE / PI);
	}

	const float lerp(const float pA, const float pB, const float pT)
	{
		return pA + (pB - pA) * pT;
	}

	const float clamp(const float pValue, const float pMin, const float pMax)
	{
		return fmax(pMin, fmin(pValue, pMax));
	}

	const float fmax(const float pA, const float pB)
	{
		return pA > pB ? pA : pB;
	}

	const float fmin(const float pA, const float pB)
	{
		return pA < pB ? pA : pB;
	}

	const float randf(const float pMin, const float pMax)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dis(pMin, pMax);

		return dis(gen);
	}

	const int randi(const int pMin, const int pMax)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(pMin, pMax);

		return dis(gen);
	}
}