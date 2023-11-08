#pragma once

namespace HezEngine
{
	enum class RendererAPIType
	{
		None,
		Vulkan,
		//D3D??,
		//Metal,
	};

	enum class PrimitiveType
	{
		None = 0,
		Triangles,
		Lines,
	};
}
