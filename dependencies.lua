-- HezEngine dependencies

-- Environment variables
VULKAN_SDK = os.getenv("VULKAN_SDK")

-- Includes
IncludeDir = {}
IncludeDir["Glad"] = "%{wks.location}/HezEngine/vendor/Glad/include"
IncludeDir["GLFW"] = "%{wks.location}/HezEngine/vendor/GLFW/include"
IncludeDir["stb_image"] = "%{wks.location}/HezEngine/vendor/stb_image"
IncludeDir["tinyobjloader"] = "%{wks.location}/HezEngine/vendor/tinyobjloader"
IncludeDir["ImGui"] = "%{wks.location}/HezEngine/vendor/ImGui"
IncludeDir["HezMaths"] = "%{wks.location}/HezEngine/vendor/HezMaths"
IncludeDir["shaderc"] = "%{wks.location}/HezEngine/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/HezEngine/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

-- Libraries directories
LibraryDir = {}
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

-- Library
Lib = {}
Lib["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Lib["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Lib["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Lib["SPRIV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Lib["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Lib["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-toolsd.lib"

Lib["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Lib["SPRIV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Lib["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"