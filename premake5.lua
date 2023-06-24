include "dependencies.lua"

workspace "MinecraftGL"
    architecture "x64"
    startproject "MinecraftGL-Game"

    configurations
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "MinecraftGL-Engine/vendor/Glad"
    include "MinecraftGL-Engine/vendor/GLFW"
    include "MinecraftGL-Engine/vendor/imgui"
group ""

group "Core"
    include "MinecraftGL-Engine"
group ""

group "Game"
    include "MinecraftGL-Game"
group ""