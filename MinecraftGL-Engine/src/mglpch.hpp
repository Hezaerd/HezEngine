#pragma once

#ifdef MGL_PLATFORM_WINDOW
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "MinecraftGL/Core/Base.hpp"

#include "MinecraftGL/Core/Log.hpp"

#ifdef MGL_PLATFORM_WINDOW
#include <Windows.h>
#endif