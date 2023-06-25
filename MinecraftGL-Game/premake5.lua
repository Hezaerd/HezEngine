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
        "%{wks.location}/MinecraftGL-Engine/vendor",
        "%{wks.location}/MinecraftGL-Engine/src"
    }

    links
    {
        "MinecraftGL-Engine"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "MGL_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MGL_RELEASE"
        runtime "Release"
        optimize "On"