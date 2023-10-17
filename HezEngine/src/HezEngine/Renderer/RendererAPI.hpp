#pragma once

#include "HezEngine/Core/Base.hpp"

#include <glm/glm.hpp>

namespace HezEngine
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, Vulkan = 1
		};

	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t pX, uint32_t pY, uint32_t pWidth, uint32_t pHeight) = 0;
		virtual void SetClearColor(const glm::vec4& pColor) = 0;
		virtual void Clear() = 0;

		static API GetAPI() { return s_API; }
		static Scope<RendererAPI> Create();

	private:
		static API s_API;
	};
}
