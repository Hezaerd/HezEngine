include "vendor/premake/customization/solution_items.lua"
include "dependencies.lua"

workspace "HezEngine"
    architecture "x64"
    startproject "HezEngine-App"

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
    include "HezEngine/vendor/Glad"
    include "HezEngine/vendor/GLFW"
    include "HezEngine/vendor/imgui"
    include "HezEngine/vendor/HezMaths"
    
group ""

group "Core"
    include "HezEngine"
group ""

group "Game"
    include "HezEngine-App"
group ""