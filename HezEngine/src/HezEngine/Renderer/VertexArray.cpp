#include "hezpch.hpp"
#include "HezEngine/Renderer/VertexArray.hpp"

#include "HezEngine/Renderer/Renderer.hpp"

namespace HezEngine
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		}

		HEZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
