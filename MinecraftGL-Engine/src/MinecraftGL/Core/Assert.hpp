#pragma once

#include "MinecraftGL/Core/Base.hpp"
#include "MinecraftGL/Core/Log.hpp"
#include <filesystem>

#define MGL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { MGL##type##ERROR(msg, __VA_ARGS__); MGL_DEBUGBREAK(); } }
#define MGL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MGL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define MGL_INTERNAL_ASSERT_NO_MSG(type, check) MGL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", MGL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define MGL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define MGL_INTERNAL_ASSERT_GET_MACRO(...) MGL_EXPAND_MACRO( MGL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MGL_INTERNAL_ASSERT_WITH_MSG, MGL_INTERNAL_ASSERT_NO_MSG) )

#define MGL_ASSERT(...) MGL_EXPAND_MACRO( MGL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define MGL_CORE_ASSERT(...) MGL_EXPAND_MACRO( MGL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )