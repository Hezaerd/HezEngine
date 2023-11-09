#include "hezpch.hpp"
#include "HezEngine/Utils/Color/Color.hpp"

namespace HezEngine
{
	// Note(Hezaerd):	No need to check if a member is between 0 and 255
	//					It will simply not compile cause members are uint8_t.
	Color::Color()
		: r(0), g(0), b(0), a(255)
	{
	}

	Color::Color(uint8_t pR, uint8_t pG, uint8_t pB, uint8_t pA)
		: r(pR), g(pG), b(pB), a(pA)
	{
	}

	std::string Color::toString() const
	{
		std::stringstream ss;
		ss << "Color(" << (int)r << "R, " << (int)g << "G, " << (int)b << "B, " << (int)a << "A)";
		return ss.str();
	}

	Color& Color::operator=(const Color& pOther)
	{
		r = pOther.r;
		g = pOther.g;
		b = pOther.b;
		a = pOther.a;

		return *this;
	}

	Color& Color::operator=(Color&& pOther) noexcept
	{
		r = pOther.r;
		g = pOther.g;
		b = pOther.b;
		a = pOther.a;

		return *this;
	}

	Color& Color::operator+=(const Color& pOther)
	{
		r += pOther.r;
		g += pOther.g;
		b += pOther.b;
		a += pOther.a;

		return *this;
	}

	Color& Color::operator-=(const Color& pOther)
	{
		r -= pOther.r;
		g -= pOther.g;
		b -= pOther.b;
		a -= pOther.a;

		return *this;
	}

	Color& Color::operator*=(const Color& pOther)
	{
		r *= pOther.r;
		g *= pOther.g;
		b *= pOther.b;
		a *= pOther.a;

		return *this;
	}

	Color Color::operator+(const Color& pOther) const
	{
		return Color(r + pOther.r, g + pOther.g, b + pOther.b, a + pOther.a);
	}

	Color Color::operator-(const Color& pOther) const
	{
		return Color(r - pOther.r, g - pOther.g, b - pOther.b, a - pOther.a);
	}

	Color Color::operator*(const Color& pOther) const
	{
		return Color(r * pOther.r, g * pOther.g, b * pOther.b, a * pOther.a);
	}

	const Color Color::Black = Color(0, 0, 0);
	const Color Color::White = Color(255, 255, 255);
	const Color Color::Red = Color(255, 0, 0);
	const Color Color::Green = Color(0, 255, 0);
	const Color Color::Blue = Color(0, 0, 255);
	const Color Color::Yellow = Color(255, 255, 0);
	const Color Color::Magenta = Color(255, 0, 255);
	const Color Color::Cyan = Color(0, 255, 255);
	const Color Color::Grey = Color(128, 128, 128);
	const Color Color::Orange = Color(255, 165, 0);
	const Color Color::Purple = Color(128, 0, 128);
	const Color Color::Pink = Color(255, 192, 203);
	const Color Color::Brown = Color(165, 42, 42);
}
