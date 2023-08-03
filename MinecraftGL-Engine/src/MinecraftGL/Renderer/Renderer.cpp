#include "mglpch.hpp"
#include "Renderer.hpp"
#include <fstream>

namespace MinecraftGL
{
	void RendererOpenGL::Init()
	{
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE);

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(RendererOpenGL::DebugCallback, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}

	unsigned int RendererOpenGL::LoadShader(const ShaderType pType, const std::string& pFilename)
	{
		int type = 0;
		switch (pType)
		{
		case ShaderType::VertexShader:
			type = GL_VERTEX_SHADER;
			break;

		case ShaderType::FragmentShader:
			type = GL_FRAGMENT_SHADER;
			break;
		default:
			MGL_CORE_ERROR("Shader type not supported");
			break;
		}
		char log[512];
		int succes;

		int shader = glCreateShader(type);
		std::string tem_src = ReadShader(pFilename);
		const char* src = tem_src.c_str();

		glShaderSource(shader, 1, &src, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &succes);
		if (!succes)
		{
			glGetShaderInfoLog(shader, 512, NULL, log);
			MGL_CORE_ERROR(log);
		}

		return shader;
	}

	unsigned int RendererOpenGL::LinkShader(const unsigned int& pVertex, const unsigned int& pFragment)
	{
		char log[512];
		int succes;
		unsigned int ID;

		ID = glCreateProgram();

		glAttachShader(ID, pVertex);
		glAttachShader(ID, pFragment);

		glLinkProgram(ID);

		glGetProgramiv(ID, GL_LINK_STATUS, &succes);
		if (!succes)
		{
			glGetProgramInfoLog(ID, 512, NULL, log);
			MGL_CORE_ERROR(log);
		}

		glUseProgram(0);
		glDeleteShader(pVertex);
		glDeleteShader(pFragment);

		return ID;
	}

	std::string RendererOpenGL::ReadShader(const std::string& pFilename)
	{
		std::string temp = "";
		std::string src = "";

		std::ifstream in_file(pFilename);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
			{
				src += temp + "\n";
			}
		}
		else
		{
			MGL_CORE_ERROR("Could not open shader file: {0}", pFilename);
		}

		in_file.close();

		return src;
	}

	void APIENTRY RendererOpenGL::DebugCallback(GLenum pSource, GLenum pType, GLuint pId, GLenum pSeverity, GLsizei /*pLength*/, const GLchar* pMessage, const void* /*pUserParam*/)
	{
		// ignore non-significant error/warning codes
		if (pId == 131169 || pId == 131185 || pId == 131218 || pId == 131204) return;

		MGL_CORE_ERROR("---------------");
		MGL_CORE_ERROR("Debug message ({0}): {1}", pId, pMessage);

		switch (pSource)
		{
		case GL_DEBUG_SOURCE_API:             MGL_CORE_ERROR("Source: API"); break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   MGL_CORE_ERROR("Source: Window System"); break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: MGL_CORE_ERROR("Source: Shader Compiler"); break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     MGL_CORE_ERROR("Source: Third Party"); break;
		case GL_DEBUG_SOURCE_APPLICATION:     MGL_CORE_ERROR("Source: Application"); break;
		case GL_DEBUG_SOURCE_OTHER:           MGL_CORE_ERROR("Source: Other"); break;
		}

		switch (pType)
		{
		case GL_DEBUG_TYPE_ERROR:               MGL_CORE_ERROR("Type: Error"); break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: MGL_CORE_ERROR("Type: Deprecated Behaviour"); break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  MGL_CORE_ERROR("Type: Undefined Behaviour"); break;
		case GL_DEBUG_TYPE_PORTABILITY:         MGL_CORE_ERROR("Type: Portability"); break;
		case GL_DEBUG_TYPE_PERFORMANCE:         MGL_CORE_ERROR("Type: Performance"); break;
		case GL_DEBUG_TYPE_MARKER:              MGL_CORE_ERROR("Type: Marker"); break;
		case GL_DEBUG_TYPE_PUSH_GROUP:          MGL_CORE_ERROR("Type: Push Group"); break;
		case GL_DEBUG_TYPE_POP_GROUP:           MGL_CORE_ERROR("Type: Pop Group"); break;
		case GL_DEBUG_TYPE_OTHER:               MGL_CORE_ERROR("Type: Other"); break;
		}

		switch (pSeverity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         MGL_CORE_ERROR("Severity: high"); break;
		case GL_DEBUG_SEVERITY_MEDIUM:       MGL_CORE_ERROR("Severity: medium"); break;
		case GL_DEBUG_SEVERITY_LOW:          MGL_CORE_ERROR("Severity: low"); break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: MGL_CORE_ERROR("Severity: notification"); break;
		}

		MGL_CORE_ERROR("---------------");

		if (pSeverity == GL_DEBUG_SEVERITY_HIGH)
			MGL_CORE_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
	}
}