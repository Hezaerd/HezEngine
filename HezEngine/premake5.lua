project "HezEngine"
    kind "StaticLib"

    targetdir ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hezpch.hpp"
    pchsource "src/hezpch.cpp"

    files {
        "src/**.hpp",
        "src/**.cpp",

        "Platform/" .. firstToUpper(os.target()) .. "/**.hpp",
        "Platform/" .. firstToUpper(os.target()) .. "/**.cpp",

        "vendor/VulkanMemoryAllocator/**.h",
        "vendor/VulkanMemoryAllocator/**.cpp",
    }

    includedirs { "src/", "vendor/", }

    IncludeDependencies()

    defines { "GLM_FORCE_DEPTH_ZERO_TO_ONE", }

    filter "files:vendor/VulkanMemoryAllocator/**.cpp"
        flags { "NoPCH" }

    filter "system:windows"
        systemversion "latest"
        defines { "HEZ_PLATFORM_WINDOWS" }

    filter "system:linux"
        defines { "HEZ_PLATFORM_LINUX" }

    filter "configurations:Debug"
        symbols "On"
        defines { "HEZ_DEBUG", "_DEBUG", }

    filter "configurations:Release"
        optimize "On"
        defines { "HEZ_RELEASE", "NDEBUG", }