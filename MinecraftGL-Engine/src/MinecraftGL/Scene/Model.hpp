#pragma once
#include <MGLMaths/Vectors.hpp>
#include <vector>
#include "MinecraftGl/Renderer/Buffer.hpp"

#define END_OF_FILE (-1)
#define PARSING_VERTEX ("v")
#define PARSING_TEXTURE_COORDS ("vt")
#define PARSING_NORMAL ("vn")
#define PARSING_FACE ("f")

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
        Model(const std::string& pPath);
        ~Model() = default;
        void Draw();

        void loadModel(const std::string& pPath);
    public:
        std::vector<Vertex> mVertexBuffer;
        std::vector<uint32_t> mIndexBuffer;

    private:
        VertexBuffer mVbo;
        VertexAttributeBuffer mVao;
    };
}