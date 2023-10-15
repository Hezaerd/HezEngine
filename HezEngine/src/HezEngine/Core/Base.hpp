#pragma once

#include <memory>

#define HEZ_DEBUGBREAK() __debugbreak()

#define HEZ_EXPAND_MACRO(x) x
#define HEZ_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

// Maybe change this to a lambda?
#define HEZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace HezEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "HezEngine/Core/Debug/Debug.hpp"
