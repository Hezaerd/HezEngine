#include "hezpch.hpp"
#include "HezEngine/Renderer/RendererAPI.hpp"

namespace HezEngine
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::Vulkan;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			//case RendererAPI::API::Vulkan:
		}

		return nullptr;
	}
}
