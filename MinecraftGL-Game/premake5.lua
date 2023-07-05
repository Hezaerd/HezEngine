project "MinecraftGL-Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs
    {
        "%{wks.location}/MinecraftGL-Engine/vendor/spdlog/include",
        "%{wks.location}/MinecraftGL-Engine/vendor/glfw/include",
        "%{wks.location}/MinecraftGL-Engine/vendor/glad/include",
        "%{wks.location}/MinecraftGL-Engine/vendor/MGLMaths",
        "%{wks.location}/MinecraftGL-Engine/src"
    }

    links
    {
        "MinecraftGL-Engine"
    }

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
        symbols "On"

    filter "configurations:Release"
        defines "MGL_RELEASE"
        runtime "Release"
        optimize "On"