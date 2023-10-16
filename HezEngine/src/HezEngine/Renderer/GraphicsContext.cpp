#include "hezpch.hpp"
#include "HezEngine/Renderer/GraphicsContext.hpp"

#include "HezEngine/Renderer/Renderer.hpp"

namespace HezEngine
{
	Scope<GraphicsContext> GraphicsContext::Create(void* /*pWindow*/)
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
