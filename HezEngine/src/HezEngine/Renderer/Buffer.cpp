#include "hezpch.hpp"
#include "HezEngine/Renderer/Buffer.hpp"

#include "HezEngine/Renderer/Renderer.hpp"

namespace HezEngine
{
	void BufferLayout::CalculateOffsetsAndStride()
	{
		uint32_t offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements)
		{
			element.Offset = offset;
			offset += element.Size;
			m_Stride += element.Size;
		}
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t /*pSize*/)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			//case RendererAPI::API::Vulkan:
		}

		HEZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(float* /*pVertices*/, uint32_t /*pSize*/)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HEZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			//case RendererAPI::API::Vulkan:
		}

		HEZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* /*pIndices*/, uint32_t /*pCount*/)
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
