#pragma once

#include "HezEngine/Core/Base.hpp"

namespace HezEngine
{
	enum class FrameBufferTextureFormat
	{
		None = 0,

		// Color
		RGBA8,
		RGBA16F,

		// Depth/Stencil
		DEPTH24STENCIL8,

		// Defaults
		Depth = DEPTH24STENCIL8
	};

	struct FrameBufferTextureSpecification
	{
		FrameBufferTextureSpecification() = default;
		FrameBufferTextureSpecification(FrameBufferTextureFormat pFormat)
			: TextureFormat(pFormat) {}

		FrameBufferTextureFormat TextureFormat = FrameBufferTextureFormat::None;
	};

	struct FrameBufferAttachmentSpecification
	{
		FrameBufferAttachmentSpecification() = default;
		FrameBufferAttachmentSpecification(std::initializer_list<FrameBufferTextureFormat> pFormats)
			: Attachments(pFormats) {}

		std::vector<FrameBufferTextureFormat> Attachments;
	};

	struct FrameBufferSpecification
	{
		uint32_t Width = 0, Height = 0;
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class FrameBuffer
	{
	public:
		virtual ~FrameBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void Resize(uint32_t pWidth, uint32_t pHeight) = 0;
		virtual void ReadPixel(uint32_t pAttachmentIndex, int pX, int pY) = 0;

		virtual void ClearAttachment(uint32_t pAttachmentIndex, int pValue) = 0;

		virtual uint32_t GetColorAttachmentRendererID(uint32_t pIndex = 0) const = 0;

		virtual const FrameBufferSpecification& GetSpecification() const = 0;

		static Ref<FrameBuffer> Create(const FrameBufferSpecification& pSpec);
	};
}
