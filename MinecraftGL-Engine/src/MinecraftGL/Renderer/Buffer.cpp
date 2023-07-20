#include "mglpch.hpp"
#include "Buffer.hpp"
#include "Renderer.hpp"
#include "MinecraftGL/Scene/Model.hpp"

namespace MinecraftGL
{
    void Buffer::GenerateBuffer()
    {
        glGenVertexArrays(1, &mVao);
        glGenBuffers(1, &mVbo);
        glGenBuffers(1, &mEbo);
    }

    void Buffer::BindBuffer(std::vector<Vertex> pVertex, std::vector<uint32_t> /*pIndices*/)
    {
        glBindVertexArray(mVao);

        glBindBuffer(GL_ARRAY_BUFFER, mVbo);
        glBufferData(GL_ARRAY_BUFFER, pVertex.size() * sizeof(Vertex), pVertex.data(), GL_STATIC_DRAW);
    }

    void Buffer::SetAttribute()
    {
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, mPosition)));
        glEnableVertexAttribArray(0);

        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, mTexCoords)));
        glEnableVertexAttribArray(1);

        // normal  attribute
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, mNormal)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Buffer::BindVao()
    {
        if (mVao == GL_FALSE)
        {
            glGenVertexArrays(1, &(GLuint)mVao);
        }
        glBindVertexArray(mVao);
    }

    void Buffer::UnbindVao()
    {
        glBindVertexArray(0);
    }
}