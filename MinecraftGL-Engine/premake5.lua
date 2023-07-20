project "MinecraftGL-Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mglpch.hpp"
    pchsource "src/mglpch.cpp"

    files
    {
        "src/**.hpp",
        "src/**.cpp",
        "vendor/stb_image/**.h",
        "vendor/stb_image/**.cpp",
        "vendor/tinyobjloader/**.h",
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.tinyobjloader}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.MGLMaths}"
    }

    links
    {
        "Glad",
        "GLFW",
        "ImGui",
        "MGLMaths",
        "opengl32.lib"
    }

    warnings "Extra"

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "MGL_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "MGL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MGL_RELEASE"
        runtime "Release"
        optimize "on"