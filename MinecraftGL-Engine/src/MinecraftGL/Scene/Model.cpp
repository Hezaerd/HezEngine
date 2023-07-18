#include "mglpch.hpp"

#include "Model.hpp"
#include "MinecraftGL/Core/Assert.hpp"
#include "MinecraftGL/Core/Log.hpp"
#include "MinecraftGL/Renderer/Renderer.hpp"

#define _CRT_SECURE_NO_WARNINGS

namespace MinecraftGL
{
    Model::Model(const std::string& pPath, MGLMaths::Vec3f& pPosition, MGLMaths::Vec3f& pRotation, MGLMaths::Vec3f& pScale)
        : mPosition(pPosition), mRotation(pRotation), mScale(pScale)
    {
        loadModel(pPath);
        MGL_CORE_INFO("Model loaded");

        mVbo.SetData(mVertexBuffer.data(), mVertexBuffer.size());
        mVao.Init();
    }

    void Model::loadModel(const std::string& pPath)
    {
        FILE* file = fopen(pPath.c_str(), "r");
        MGL_CORE_ASSERT(file, "Failed to open file");

        while (true)
        {
            char lineHeader[128];

            int res = fscanf(file, "%s", lineHeader);
            if (res == END_OF_FILE)
                break;

            Vertex vertex;

            if (strcmp(lineHeader, PARSING_VERTEX) == 0)
            {
                fscanf(file, "%f %f %f\n", &vertex.mPosition.x, &vertex.mPosition.y, &vertex.mPosition.z);
                mVertexBuffer.emplace_back(vertex);
            }
            if (strcmp(lineHeader, PARSING_TEXTURE_COORDS) == 0)
            {
                fscanf(file, "%f %f\n", &vertex.mTexCoords.x, &vertex.mTexCoords.y);
                mVertexBuffer.emplace_back(vertex);
            }
            if (strcmp(lineHeader, PARSING_NORMAL) == 0)
            {
                fscanf(file, "%f %f %f\n", &vertex.mNormal.x, &vertex.mNormal.y, &vertex.mNormal.z);
                mVertexBuffer.emplace_back(vertex);
            }
            if (strcmp(lineHeader, PARSING_FACE) == 0)
            {
                uint32_t vertexIndex[3], textureIndex[3], normalIndex[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                    &vertexIndex[0], &textureIndex[0], &normalIndex[0],
                    &vertexIndex[1], &textureIndex[1], &normalIndex[1],
                    &vertexIndex[2], &textureIndex[2], &normalIndex[2]);
                if (matches != 9)
                {
                    MGL_CORE_ERROR("File can't be read by our simple parser : ( Try exporting with other options\n");
                    return;
                }
                mIndexBuffer.emplace_back(vertexIndex[0]);
                mIndexBuffer.emplace_back(vertexIndex[1]);
                mIndexBuffer.emplace_back(vertexIndex[2]);
            }
            else
            {
                char stupidBuffer[1000];
                fgets(stupidBuffer, 1000, file);
            }
        }
    }

    MGLMaths::Mat4f Model::getModelMatrix()
    {
        return MGLMaths::Mat4f::Transform(mPosition, mRotation, mScale);
    }

    void Model::Draw()
    {
        mVao.Bind();

        glBindBuffer(GL_ARRAY_BUFFER, mVbo.mId);

        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mVertexBuffer.size()));
    }
}