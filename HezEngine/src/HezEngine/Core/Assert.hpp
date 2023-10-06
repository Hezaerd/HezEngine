#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Log.hpp"
#include <filesystem>

#define HEZ_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { HEZ##type##ERROR(msg, __VA_ARGS__); HEZ_DEBUGBREAK(); } }
#define HEZ_INTERNAL_ASSERT_WITH_MSG(type, check, ...) HEZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define HEZ_INTERNAL_ASSERT_NO_MSG(type, check) HEZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", HEZ_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define HEZ_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define HEZ_INTERNAL_ASSERT_GET_MACRO(...) HEZ_EXPAND_MACRO( HEZ_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, HEZ_INTERNAL_ASSERT_WITH_MSG, HEZ_INTERNAL_ASSERT_NO_MSG) )

#define HEZ_ASSERT(...) HEZ_EXPAND_MACRO( HEZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define HEZ_CORE_ASSERT(...) HEZ_EXPAND_MACRO( HEZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )