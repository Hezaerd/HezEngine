#include "mglpch.hpp"
#include "Renderer.hpp"
#include <fstream>

namespace MinecraftGL
{
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
            throw std::logic_error("Not a supported type");
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
            MGL_CORE_ERROR("Not a good file my comrade");
        }

        in_file.close();

        return src;
    }
}