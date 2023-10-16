#pragma once

#include <string>
#include <HezMaths/HezMaths.hpp>

namespace HezEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0; // Should not be called normally! Debug only!

		virtual const std::string& GetName() const = 0;

		virtual void SetInt(const std::string& pName, int pValue) = 0;
		virtual void SetIntArray(const std::string& pName, int* pValues, uint32_t pCount) = 0;
		virtual void SetFloat(const std::string& pName, float pValue) = 0;
		virtual void SetFloat2(const std::string& pName, const HezMaths::Vec2f& pValue) = 0;
		virtual void SetFloat3(const std::string& pName, const HezMaths::Vec3f& pValue) = 0;
		virtual void SetFloat4(const std::string& pName, const HezMaths::Vec4f& pValue) = 0;
		virtual void SetMat3(const std::string& pName, const HezMaths::Mat3f& pValue) = 0;
		virtual void SetMat4(const std::string& pName, const HezMaths::Mat4f& pValue) = 0;

		static Ref<Shader> Create(const std::string& pFilePath);
		static Ref<Shader> Create(const std::string& pName, const std::string& pVertexSrc, const std::string& pFragmentSrc);
	};
}
