#include "hezpch.hpp"
#include "HezEngine/Utils/Color/ColorUtils.hpp"

namespace HezEngine
{
	//Note(Hezaerd):	Hex format for color is (#)AARRGGBB

	Color ColorUtils::FromHex(const int pHex)
	{
		// No need to check for an alpha component.
		// int is too short to hold more than 6 hex digits.
		// so alpha component will be 255 by default

		int r = (pHex >> 16) & 0xFF;
		int g = (pHex >> 8) & 0xFF;
		int b = pHex & 0xFF;

		return Color(r, g, b, 255);;
	}

	Color ColorUtils::FromHex(const unsigned long pHex)
	{
		int a = (pHex >> 24) & 0xFF;
		int r = (pHex >> 16) & 0xFF;
		int g = (pHex >> 8) & 0xFF;
		int b = pHex & 0xFF;

		return Color(r, g, b, a);
	}

	Color ColorUtils::FromHex(std::string pHex)
	{
		if (pHex[0] == '#')
			pHex.erase(0, 1);

		if (pHex.length() == 6) // No alpha component and can be stored as an int.
			return FromHex(std::stoi(pHex, nullptr, 16));

		return FromHex(std::stoul(pHex, nullptr, 16));
	}

	Color ColorUtils::Lerp(const Color pA, const Color pB, float pT)
	{
		if (pT < 0.0f)
			pT = 0.0f;
		else if (pT > 1.0f)
			pT = 1.0f;

		float r = pA.r + (pB.r - pA.r) * pT;
		float g = pA.g + (pB.g - pA.g) * pT;
		float b = pA.b + (pB.b - pA.b) * pT;
		float a = pA.a + (pB.a - pA.a) * pT;

		Color color(r, g, b, a);
		HEZ_CORE_INFO_TAG("ColorUtils", "Lerp(const Color, const Color, float): {0}", color.ToString());
		return Color(r, g, b, a);
	}
}
