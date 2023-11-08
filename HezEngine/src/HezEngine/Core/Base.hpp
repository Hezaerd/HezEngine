#pragma once

#include <memory>

#ifdef HEZ_PLATFORM_WINDOWS
#define HEZ_DEBUGBREAK() __debugbreak()
#else
#define HEZ_DEBUGBREAK()
#endif

#define HEZ_EXPAND_MACRO(x) x
#define HEZ_STRINGIFY_MACRO(x) #x

// bit shifting macro
#define BIT(x) (1 << x)

#define HEZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace HezEngine
{
	void InitializeCore();
	void ShutdownCore();
}

namespace HezEngine
{
	// Unique ptr wrapper
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	// Shared ptr wrapper
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	// Types
	using byte = uint8_t;
}

#include "HezEngine/Core/Debug/Debug.hpp"
