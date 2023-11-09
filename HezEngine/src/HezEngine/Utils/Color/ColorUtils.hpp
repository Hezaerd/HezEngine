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
	};
}
