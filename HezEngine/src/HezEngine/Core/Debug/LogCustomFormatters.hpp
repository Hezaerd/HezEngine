#pragma once

#include <glm/glm.hpp>

#include <spdlog/fmt/fmt.h>

namespace fmt
{
	template<>
	struct formatter<glm::vec2>
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
		auto format(const glm::vec2& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f})", pVec.x, pVec.y)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e})", pVec.x, pVec.y);
		}
	};

	template<>
	struct formatter<glm::vec3>
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
		auto format(const glm::vec3& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f}, {:.3f})", pVec.x, pVec.y, pVec.z)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e}, {:.3e})", pVec.x, pVec.y, pVec.z);
		}
	};

	template<>
	struct formatter<glm::vec4>
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
		auto format(const glm::vec4& pVec, FormatContext& pCtx) const -> decltype(pCtx.out())
		{
			return presentation == 'f'
				? fmt::format_to(pCtx.out(), "({:.3f}, {:.3f}, {:.3f}, {:.3f})", pVec.x, pVec.y, pVec.z, pVec.w)
				: fmt::format_to(pCtx.out(), "({:.3e}, {:.3e}, {:.3e}, {:.3e})", pVec.x, pVec.y, pVec.z, pVec.w);
		}
	};
}
