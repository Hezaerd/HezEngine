#pragma once
#include <MGLMaths/Vectors.hpp>
#include <vector>
#include "MinecraftGl/Renderer/Buffer.hpp"
#include "MGLMaths/Matrices.hpp"

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
		Model(const std::string& pPath, const MGLMaths::Vec3f& mPosition = MGLMaths::Vec3f::Zero, const MGLMaths::Vec3f& mRotation = MGLMaths::Vec3f::Zero, const MGLMaths::Vec3f& mScale = { 1.0f,1.0f,1.0f });
		~Model() = default;
		void Draw();

		void LoadModel(const std::string& pPath);

		MGLMaths::Mat4f GetModelMatrix();
	public:
		std::vector<Vertex> mVertexBuffer;
		std::vector<uint32_t> mIndexBuffer;

		MGLMaths::Vec3f mPosition, mRotation, mScale;

	private:
		Buffer mBuffer;
	};
}