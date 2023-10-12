include "vendor/premake/premake_customization/solution_items.lua"
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
    include "HezEngine/vendor/ImGui"
    include "HezEngine/vendor/HezMaths"   
group ""

group "Premake"
    include "vendor/premake"
group ""

group "Core"
    include "HezEngine"
group ""

group "Editor"
    include "HezEngine-App"
group ""