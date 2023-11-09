#pragma once

typedef unsigned char uint8_t;

namespace HezEngine
{
	class Color
	{
	public:
		Color();
		Color(uint8_t pR, uint8_t pG, uint8_t pB, uint8_t pA = 255);
		Color(const Color& pOther);
		Color(Color&& pOther) noexcept;

		std::string toString() const;

	public:
		Color& operator=(const Color& pOther);
		Color& operator=(Color&& pOther) noexcept;

	public:
		static const Color Black;
		static const Color White;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Magenta;
		static const Color Cyan;
		static const Color Grey;
		static const Color Orange;
		static const Color Purple;
		static const Color Pink;
		static const Color Brown;

	public:
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
}
