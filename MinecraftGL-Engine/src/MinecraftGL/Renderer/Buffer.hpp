#pragma once
#include <cstdint>

namespace MinecraftGL
{
    class IBuffer
    {
    public:

        IBuffer() = default;

        IBuffer(unsigned int& pID, const void* pData, const unsigned int pSize)
            : mId(pID), mData(pData), mSize(pSize)
        {
        }

        virtual void SetData(const void* pData, const unsigned int pSize) = 0;

    public:

        unsigned int mId;
        const void* mData = nullptr;
        unsigned int mSize = 0;
    };

    class VertexBuffer : public IBuffer
    {
    public:
        VertexBuffer(unsigned int& pID, const void* pData, const unsigned int pSize);
        ~VertexBuffer();

        void SetData(const void* pData, const unsigned int pSize) override;
    };

    class IndexBuffer : public IBuffer
    {
    public:
        IndexBuffer(unsigned int& pID, const void* pData, const unsigned int pSize);
        ~IndexBuffer();

        void SetData(const void* pData, const unsigned int pSize) override;
    };

    class VertexAttributeBuffer
    {
    public:

        VertexAttributeBuffer();

        ~VertexAttributeBuffer();

        void Bind() const;
        void Unbind() const;

    public:
        unsigned int mVertexAttributeBufferID;
        std::vector<struct Vertex> mVertexAttributeBufferData;
        std::vector<uint32_t> m_IndexBuffer;
    };
};