#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Debug/Log.hpp"

#ifdef HEZ_DEBUG
#define HEZ_ENABLE_ASSERTS
#endif

#ifdef HEZ_ENABLE_ASSERTS
#define HEZ_CORE_ASSERT_MESSAGE_INTERNAL(...) ::HezEngine::Log::PrintAssertMessage(::HezEngine::Log::Type::Core, "Assertion failed" __VA_OPT__(,) __VA_ARGS__)
#define HEZ_ASSERT_MESSAGE_INTERNAL(...) ::HezEngine::Log::PrintAssertMessage(::HezEngine::Log::Type::Client, "Assertion failed" __VA_OPT__(,) __VA_ARGS__)

#define HEZ_CORE_ASSERT(condition, ...) {if(!(condition)) { HEZ_CORE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); HEZ_DEBUGBREAK(); }}
#define HEZ_ASSERT(condition, ...) {if(!(condition)) {HEZ_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); HEZ_DEBUGBREAK(); }}
#else
#define HEZ_CORE_ASSERT(condition, ...)
#define HEZ_ASSERT(condition, ...)
#endif
