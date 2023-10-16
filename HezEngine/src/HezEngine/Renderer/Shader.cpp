#include "hezpch.hpp"
#include "HezEngine/Renderer/Shader.hpp"

#include "HezEngine/Renderer/Renderer.hpp"

namespace HezEngine
{
	Ref<Shader> Shader::Create(const std::string& pFilePath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			//case RendererAPI::API::Vulkan:
		}

		HEZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& pName, const std::string& pVertexSrc, const std::string& pFragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			//case RendererAPI::API::Vulkan:
		}

		HEZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
