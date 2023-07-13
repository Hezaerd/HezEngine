#pragma once

#include <MGLMaths/MGLMaths.hpp>

namespace MinecraftGL
{
    class Shader
    {
    public:
        /*Shader(const std::string& pFilePath);*/
        Shader(const std::string& pName, const std::string& pVertexSrc, const std::string& pFragmentSrc);
        ~Shader() = default;

        void Bind() const;
        void Unbind() const;

        void SetInt(const std::string& pName, int pValue);
        void SetFloat(const std::string& pName, float pValue);
        void SetFloat3(const std::string& pName, const MGLMaths::Vec3f& pValue);
        void SetFloat4(const std::string& pName, const MGLMaths::Vec4f& pValue);
        void SetMat4(const std::string& pName, const MGLMaths::Mat4f& pValue);

        unsigned int CreateShader(const std::string& pVertexShader, const std::string& pFragmentShader);

        void LinkProgram(unsigned int pVertex, unsigned int pFragment);

    public:
        std::string mName;

        unsigned int mShaderProgramID;
    };
}