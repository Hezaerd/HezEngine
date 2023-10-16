#pragma once

#include "HezEngine/Renderer/RendererAPI.hpp"

namespace HezEngine
{
	class RenderCommand
	{
	public:
		static void Init();
		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		static void SetClearColor(const HezMaths::Vec4f& color);
		static void Clear();

	private:
		static Scope<RendererAPI> s_RendererAPI;
	};
}
