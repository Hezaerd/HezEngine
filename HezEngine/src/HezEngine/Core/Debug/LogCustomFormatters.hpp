#pragma once

#include <HezMaths/HezMaths.hpp>

#include <spdlog/fmt/fmt.h>

namespace fmt
{
	template<>
	struct formatter<HezMaths::Vec2f>
	{
		char presentation = 'f';

		constexpr auto parse(format_parse_context& pCtx) -> decltype(pCtx.begin())
		{
			auto it = pCtx.begin(), end = pCtx.end();
			if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

			if (it != end && *it != '}') throw format_error("invalid format");

			return it;
		}

		template <typename FormatContext>
		auto format(const HezMaths::Vec2f& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f})", pVec.x, pVec.y)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e})", pVec.x, pVec.y);
		}
	};

	template<>
	struct formatter<HezMaths::Vec3f>
	{
		char presentation = 'f';

		constexpr auto parse(format_parse_context& pCtx) -> decltype(pCtx.begin())
		{
			auto it = pCtx.begin(), end = pCtx.end();
			if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

			if (it != end && *it != '}') throw format_error("invalid format");

			return it;
		}

		template <typename FormatContext>
		auto format(const HezMaths::Vec3f& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f}, {:.3f})", pVec.x, pVec.y, pVec.z)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e}, {:.3e})", pVec.x, pVec.y, pVec.z);
		}
	};

	template<>
	struct formatter<HezMaths::Vec4f>
	{
		char presentation = 'f';

		constexpr auto parse(format_parse_context& pCtx) -> decltype(pCtx.begin())
		{
			auto it = pCtx.begin(), end = pCtx.end();
			if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

			if (it != end && *it != '}') throw format_error("invalid format");

			return it;
		}

		template <typename FormatContext>
		auto format(const HezMaths::Vec4f& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f}, {:.3f}, {:.3f})", pVec.x, pVec.y, pVec.z, pVec.w)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e}, {:.3e}, {:.3e})", pVec.x, pVec.y, pVec.z, pVec.w);
		}
	};
}
