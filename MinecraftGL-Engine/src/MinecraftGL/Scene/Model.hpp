#pragma once
#include <MGLMaths/Vectors.hpp>
#include <vector>
#include "MinecraftGl/Renderer/Buffer.hpp"
#include "MGLMaths/Matrices.hpp"

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
        Model(const std::string& pPath, MGLMaths::Vec3f& mPosition, MGLMaths::Vec3f& mRotation, MGLMaths::Vec3f& mScale);
        ~Model() = default;
        void Draw();

        void loadModel(const std::string& pPath);

        MGLMaths::Mat4f getModelMatrix();
    public:
        std::vector<Vertex> mVertexBuffer;
        std::vector<uint32_t> mIndexBuffer;

        MGLMaths::Vec3f mPosition, mRotation, mScale;

    private:
        VertexBuffer mVbo;
        VertexAttributeBuffer mVao;
    };
}