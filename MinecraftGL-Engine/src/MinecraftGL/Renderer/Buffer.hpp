#pragma once
#include <cstdint>

namespace MinecraftGL
{
    class Buffer
    {
    public:

        Buffer() = default;
        void GenerateBuffer();
        void BindBuffer(std::vector<struct Vertex> pVertex, std::vector<uint32_t> pIndices);

        void SetAttribute();

        void BindVao();
        void UnbindVao();

    public:

        unsigned int mVbo, mEbo, mVao;
        const void* mData = nullptr;
        unsigned int mSize = 0;
    };
};