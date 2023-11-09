#pragma once

#include "HezEngine/Utils/Color/Color.hpp"

namespace HezEngine
{
	class ColorUtils
	{
	public:
		static Color FromHex(const int pHex);
		static Color FromHex(const unsigned long pHex);
		static Color FromHex(std::string pHex);

		static Color Lerp(const Color pA, const Color pB, float pT);
	};
}
