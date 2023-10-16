#pragma once

#include "HezEngine/Renderer/RenderCommand.hpp"

namespace HezEngine
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}
