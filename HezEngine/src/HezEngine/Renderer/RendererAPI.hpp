#pragma once

#include "HezEngine/Renderer/Types.hpp"

namespace HezEngine
{
	class RendererAPI
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		inline static RendererAPIType Current() { return s_CurrentRendererAPI; };

	private:
		inline static RendererAPIType s_CurrentRendererAPI = RendererAPIType::Vulkan; // Vulkan is default for now
	};
}
