#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Debug/Log.hpp"

// Verify are just like asserts, but instead of passing it an expression,
// you pass it a condition directly.

// Example :
// HEZ_VERIFY(m_RendererAPI->GetAPIType() == RendererAPIType::Vulkan, "RendererAPI is not Vulkan!");

#ifdef HEZ_ENABLE_VERIFY
#define HEZ_CORE_VERIFY_MESSAGE_INTERNAL(...)  ::HezEngine::Log::PrintAssertMessage(::HezEngine::Log::Type::Core, "Verify Failed" __VA_OPT__(,) __VA_ARGS__)
#define HEZ_VERIFY_MESSAGE_INTERNAL(...)  ::HezEngine::Log::PrintAssertMessage(::HezEngine::Log::Type::Client, "Verify Failed" __VA_OPT__(,) __VA_ARGS__)

#define HEZ_CORE_VERIFY(condition, ...) { if(!(condition)) { HEZ_CORE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); HEZ_DEBUG_BREAK; } }
#define HEZ_VERIFY(condition, ...) { if(!(condition)) { HEZ_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); HEZ_DEBUG_BREAK; } }
#else
#define HEZ_CORE_VERIFY(condition, ...)
#define HEZ_VERIFY(condition, ...)
#endif
