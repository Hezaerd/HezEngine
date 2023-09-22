#pragma once

#include <MGLMaths/MGLMaths.hpp>
#include "glad/glad.h"

namespace MinecraftGL
{
	enum class ShaderType
	{
		VertexShader = GL_VERTEX_SHADER,
		FragmentShader = GL_FRAGMENT_SHADER
	};

	class RendererOpenGL
	{
	public:
		RendererOpenGL() = default;
		~RendererOpenGL() = default;

		static void Init();

		static unsigned int LoadShader(const ShaderType pType, const std::string& pFilename);
		static unsigned int LinkShader(const unsigned int& pVertex, const unsigned int& pFragment);

		static void SetViewport(uint32_t width, uint32_t height);
		static void SetClearColor(const MGLMaths::Vec4f& pColor);
		static void Clear();

	private:
		static std::string ReadShader(const std::string& pFilename);

		static void APIENTRY DebugCallback(GLenum pSource, GLenum pType, GLuint pId, GLenum pSeverity, GLsizei pLength, const GLchar* pMessage, const void* pUserParam);
	};
};