project "HezEngine-App"
    kind "ConsoleApp"

    targetdir ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs {
        "src/",

        "%{wks.location}/HezEngine/src/",
        "%{wks.location}/HezEngine/vendor/",
    }

    links
    {
        "HezEngine"
    }

    warnings "Extra"

    filter "system:windows"
        systemversion "latest"
        defines { "HEZ_PLATFORM_WINDOWS", }

    filter "configurations:Debug"
        symbols "On"
        defines { "HEZ_DEBUG" }
        ProcessDependencies("Debug")

    filter "configurations:Release"
        optimize "On"
        defines { "HEZ_RELEASE" }
        ProcessDependencies("Release")

    filter "files:**.hlsl"
        flags { "ExcludeFromBuild" }