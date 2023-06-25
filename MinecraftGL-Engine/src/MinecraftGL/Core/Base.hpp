#pragma once

#include <memory>

#define MGL_DEBUGBREAK() __debugbreak()

#define MGL_EXPAND_MACRO(x) x
#define MGL_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

namespace MinecraftGL
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

#include "MinecraftGL/Core/Assert.hpp"
#include "MinecraftGL/Core/Log.hpp"