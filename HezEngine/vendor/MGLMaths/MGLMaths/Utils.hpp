#pragma once

#define PI 3.14159265358979323846f
#define EPSILON 0.00001f
#define HALF_CIRCLE 180.0f

namespace MGLMaths
{
	const double toRadians(const double& pDegrees);
	const double toDegrees(const double& pRadians);

	const float lerp(const float pA, const float pB, const float pT);
	const float clamp(const float pValue, const float pMin, const float pMax);
	const float fmax(const float pA, const float pB);
	const float fmin(const float pA, const float pB);

	const float randf(const float pMin, const float pMax);
	const int randi(const int pMin, const int pMax);
}