#include "mglpch.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"

namespace MinecraftGL
{
    Shader::Shader(const std::string& pName, const std::string& pVertexSrc, const std::string& pFragmentSrc)
    {
        mName = pName;
        mShaderProgramID = CreateShader(pVertexSrc, pFragmentSrc);
    }

    void Shader::Bind() const
    {
        glUseProgram(mShaderProgramID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::SetInt(const std::string& pName, int pValue)
    {
        glUniform1i(glGetUniformLocation(mShaderProgramID, pName.c_str()), pValue);
    }

    void Shader::SetFloat(const std::string& pName, float pValue)
    {
        glUniform1f(glGetUniformLocation(mShaderProgramID, pName.c_str()), pValue);
    }

    void Shader::SetFloat3(const std::string& pName, const MGLMaths::Vec3f& pValue)
    {
        glUniform3fv(glGetUniformLocation(mShaderProgramID, pName.c_str()), 1, pValue.GetPointer());
    }

    void Shader::SetFloat4(const std::string& pName, const MGLMaths::Vec4f& pValue)
    {
        glUniform4fv(glGetUniformLocation(mShaderProgramID, pName.c_str()), 1, pValue.GetPointer());
    }

    void Shader::SetMat4(const std::string& pName, const MGLMaths::Mat4f& pValue)
    {
        glUniformMatrix4fv(glGetUniformLocation(mShaderProgramID, pName.c_str()), 1, GL_FALSE, pValue.GetPointer());
    }

    unsigned int Shader::CreateShader(const std::string& pVertexShader, const std::string& pFragmentShader)
    {
        unsigned int vertexShader;

        vertexShader = RendererOpenGL::LoadShader(ShaderType::VertexShader, pVertexShader);

        unsigned int fragmentShader;

        fragmentShader = RendererOpenGL::LoadShader(ShaderType::FragmentShader, pFragmentShader);

        return RendererOpenGL::LinkShader(vertexShader, fragmentShader);
    }

    void Shader::LinkProgram(unsigned int pVertex, unsigned int pFragment)
    {
        mShaderProgramID = RendererOpenGL::LinkShader(pVertex, pFragment);
    }
}