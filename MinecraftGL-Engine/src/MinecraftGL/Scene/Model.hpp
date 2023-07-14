#pragma once
#include <MGLMaths/Vectors.hpp>

namespace MinecraftGL
{
    struct Vertex
    {
        MGLMaths::Vec3f mPosition;
        MGLMaths::Vec3f mNormal;
        MGLMaths::Vec2f mTexCoords;
    };

    /* class Model
     {
     public:
         Model();
         ~Model();
     };*/
}