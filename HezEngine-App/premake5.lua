project "HezEngine-App"
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
        "%{wks.location}/HezEngine/vendor/spdlog/include",
        "%{wks.location}/HezEngine/vendor/glfw/include",
        "%{wks.location}/HezEngine/vendor/glad/include",
        "%{wks.location}/HezEngine/vendor/MGLMaths",
        "%{wks.location}/HezEngine/src"
    }

    links
    {
        "HezEngine"
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
        symbols "On"

    filter "configurations:Release"
        defines "HEZ_RELEASE"
        runtime "Release"
        optimize "On"