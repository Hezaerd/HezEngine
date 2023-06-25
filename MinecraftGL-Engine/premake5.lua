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
        "vendor/stb_image/**.cpp"
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "Glad",
        "GLFW",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "MGL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MGL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MGL_RELEASE"
        runtime "Release"
        optimize "on"