#pragma once

#ifdef HEZ_PLATFORM_WINDOWS
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "HezEngine/Core/Base.hpp"

#ifdef HEZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif
