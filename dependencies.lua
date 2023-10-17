-- HezEngine dependencies
include "./vendor/premake/premake_customization/ordered_pairs.lua"

-- Utility function for converting the first char of a string to uppercase
function firstToUpper(str)
    return (str:gsub("^%l", string.upper))
end

-- Get Vulkan SDK path
VULKAN_SDK = os.getenv("VULKAN_SDK")


Dependencies = {
    Vulkan = {
        Windows = {
            LibName = "vulkan-1",
            IncludeDir = "%{VULKAN_SDK}/Include",
            LibDir = "%{VULKAN_SDK}/Lib/",
        }
    },
    ShaderC = {
        LibName = "shaderc_shared",
        IncludeDir = "%{wks.location}/HezEngine/vendor/shaderc/include",
        Windows = { DebugLibName = "shaderc_sharedd", },
        Configuratons = "Debug, Release"
    },
    ShaderCUtil = {
        LibName = "shaderc_util",
        IncludeDir = "%{wks.location}/HezEngine/vendor/shaderc/libshaderc_util/include",
        Windows = {DebugLibName = "shaderc_utild", },
        Configuratons = "Debug, Release"
    },
    SPIRVCrossCore = {
		LibName = "spirv-cross-core",
		Windows = { DebugLibName = "spirv-cross-cored", },
		Configurations = "Debug,Release"
	},
	SPIRVCrossGLSL = {
		LibName = "spirv-cross-glsl",
		Windows = { DebugLibName = "spirv-cross-glsld", },
		Configurations = "Debug,Release"
	},
	SPIRVTools = {
		LibName = "SPIRV-Tools",
		Windows = { DebugLibName = "SPIRV-Toolsd", },
		Configurations = "Debug,Release"
    },
    GLFW = {
        LibName = "GLFW",
        IncludeDir = "%{wks.location}/HezEngine/vendor/GLFW/include",
    },
    ImGui = {
        LibName = "ImGui",
        IncludeDir = "%{wks.location}/HezEngine/vendor/ImGui",
    },
	GLM = {
		IncludeDir = "%{wks.location}/HezEngine/vendor/glm",
	},
    STB_Image = {
        IncludeDir = "%{wks.location}/HezEngine/vendor/stb_image/include",
    },
}

function LinkDependency(table, is_debug, target)

    -- Setup lib dir
    if table.LibDir ~= nil then
        libdirs { table.LibDir }
    end

    -- Try linking
    local libraryName = nil
	if table.LibName ~= nil then
		libraryName = table.LibName
	end

	if table.DebugLibName ~= nil and is_debug and target == "Windows" then
		libraryName = table.DebugLibName
	end

	if libraryName ~= nil then
		links { libraryName }
		return true
	end

	return false
end

function AddDependencyIncludes(table)
	if table.IncludeDir ~= nil then
		externalincludedirs { table.IncludeDir }
	end
end

function ProcessDependencies(config_name)
    local target = firstToUpper(os.target())

	for key, libraryData in orderedPairs(Dependencies) do

		-- Always match config_name if no Configurations list is specified
		local matchesConfiguration = true

		if config_name ~= nil and libraryData.Configurations ~= nil then
			matchesConfiguration = string.find(libraryData.Configurations, config_name)
		end

		local isDebug = config_name == "Debug"

		if matchesConfiguration then
			local continueLink = true

			-- Process Platform Scope
			if libraryData[target] ~= nil then
				continueLink = not LinkDependency(libraryData[target], isDebug, target)
				AddDependencyIncludes(libraryData[target])
			end

			-- Process Global Scope
			if continueLink then
				LinkDependency(libraryData, isDebug, target)
			end

			AddDependencyIncludes(libraryData)
		end

	end
end

function IncludeDependencies(config_name)
	local target = firstToUpper(os.target())

	for key, libraryData in orderedPairs(Dependencies) do

		-- Always match config_name if no Configurations list is specified
		local matchesConfiguration = true

		if config_name ~= nil and libraryData.Configurations ~= nil then
			matchesConfiguration = string.find(libraryData.Configurations, config_name)
		end

		if matchesConfiguration then
			-- Process Global Scope
			AddDependencyIncludes(libraryData)

			-- Process Platform Scope
			if libraryData[target] ~= nil then
				AddDependencyIncludes(libraryData[target])
			end
		end

	end
end