project "HezEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hezpch.hpp"
    pchsource "src/hezpch.cpp"

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
        "src/",
        "vendor/",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.tinyobjloader}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.HezMaths}",
        "%{IncludeDir.VulkanSDK}",
    }

    links
    {
        "Glad",
        "GLFW",
        "ImGui",
        "HezMaths",
        "opengl32.lib"
    }

    warnings "Extra"

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HEZ_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "HEZ_DEBUG"
        runtime "Debug"
        symbols "on"

        links
        {
            "%{Lib.ShaderC_Debug}",
            "%{Lib.SPRIV_Cross_Debug}",
            "%{Lib.SPIRV_Cross_GLSL_Debug}",
        }

    filter "configurations:Release"
        defines "HEZ_RELEASE"
        runtime "Release"
        optimize "on"

        links
        {
            "%{Lib.ShaderC_Release}",
            "%{Lib.SPRIV_Cross_Release}",
            "%{Lib.SPIRV_Cross_GLSL_Release}",
        }