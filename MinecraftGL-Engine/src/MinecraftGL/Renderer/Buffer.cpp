#include "mglpch.hpp"
#include "Buffer.hpp"
#include "Renderer.hpp"
#include "Model.hpp"

namespace MinecraftGL
{
    VertexBuffer::VertexBuffer(unsigned int& pID, const void* pData, const unsigned int pSize)
    {
        mId = pID;
        mData = pData;
        mSize = pSize;
        glGenBuffers(1, &mId);
        glBindBuffer(GL_ARRAY_BUFFER, mId);
        glBufferData(GL_ARRAY_BUFFER, mSize, mData, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &mId);
    }

    void VertexBuffer::SetData(const void* pData, const unsigned int pSize)
    {
        mData = pData;
        mSize = pSize;
        glBindBuffer(GL_ARRAY_BUFFER, mId);
        glBufferData(GL_ARRAY_BUFFER, mSize, mData, GL_STATIC_DRAW);
    }

    IndexBuffer::IndexBuffer(unsigned int& pID, const void* pData, const unsigned int pSize)
    {
        mId = pID;
        mData = pData;
        mSize = pSize;
        glGenBuffers(1, &mId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mSize, mData, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &mId);
    }

    void IndexBuffer::SetData(const void* pData, const unsigned int pSize)
    {
        mData = pData;
        mSize = pSize;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mSize, mData, GL_STATIC_DRAW);
    }

    VertexAttributeBuffer::VertexAttributeBuffer()
    {
        glGenVertexArrays(1, &mVertexAttributeBufferID);
        glBindVertexArray(mVertexAttributeBufferID);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, m_Position)));
        glEnableVertexAttribArray(0);

        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, m_TextCoords)));
        glEnableVertexAttribArray(1);

        // normal  attribute
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, m_Normal)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    VertexAttributeBuffer::~VertexAttributeBuffer()
    {
        glDeleteVertexArrays(1, &mVertexAttributeBufferID);
    }

    void VertexAttributeBuffer::Bind() const
    {
        if (mVertexAttributeBufferID == GL_FALSE)
        {
            glGenVertexArrays(1, &(GLuint)mVertexAttributeBufferID);
        }
        glBindVertexArray(mVertexAttributeBufferID);
    }

    void VertexAttributeBuffer::Unbind() const
    {
        glBindVertexArray(0);
    }
}