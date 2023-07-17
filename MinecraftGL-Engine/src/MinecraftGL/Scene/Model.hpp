#pragma once
#include <MGLMaths/Vectors.hpp>
#include <vector>

namespace MinecraftGL
{
    struct Vertex
    {
        MGLMaths::Vec3f mPosition;
        MGLMaths::Vec2f mTexCoords;
        MGLMaths::Vec3f mNormal;
    };

    class Model
    {
    public:
        Model();
        ~Model() = default;
        void Draw();
    public:
        std::vector<Vertex> mVertexBuffer;
        std::vector<uint32_t> mIndexBuffer;



    private:
    };
}