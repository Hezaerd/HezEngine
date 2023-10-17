#include "hezpch.hpp"
#include "HezEngine/Renderer/RenderCommand.hpp"

namespace HezEngine
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

	void RenderCommand::Init()
	{
		s_RendererAPI->Init();
	}

	void RenderCommand::SetViewport(uint32_t pX, uint32_t pY, uint32_t pWidth, uint32_t pHeight)
	{
		s_RendererAPI->SetViewport(pX, pY, pWidth, pHeight);
	}

	void RenderCommand::SetClearColor(const glm::vec4& pColor)
	{
		s_RendererAPI->SetClearColor(pColor);
	}

	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}
}
