#include "mglpch.hpp"

#include "Model.hpp"
#include "MinecraftGL/Core/Assert.hpp"
#include "MinecraftGL/Core/Log.hpp"
#include "MinecraftGL/Renderer/Renderer.hpp"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

namespace MinecraftGL
{
	Model::Model(const std::string& pPath, const MGLMaths::Vec3f& pPosition, const MGLMaths::Vec3f& pRotation, const MGLMaths::Vec3f& pScale)
		: mPosition(pPosition), mRotation(pRotation), mScale(pScale)
	{
		LoadModel(pPath);

		mBuffer.GenerateBuffer();
		mBuffer.BindBuffer(mVertexBuffer, mIndexBuffer);
		mBuffer.SetAttribute();
	}

	void Model::LoadModel(const std::string& pPath)
	{
		MGL_CORE_TRACE("Loading model: {0}", pPath);

		bool modelLoaded = false;

		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;

		std::string warn, err;

		modelLoaded = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, pPath.c_str());
		if (!modelLoaded)
		{
			MGL_CORE_ERROR("---------------");
			MGL_CORE_ERROR("Failed to load model: {0}", pPath);
			MGL_CORE_ERROR("Warning: {0}", warn);
			MGL_CORE_ERROR("Error: {0}", err);
			MGL_CORE_ERROR("---------------");
			return;
		}
		MGL_CORE_TRACE("Successfully loaded model: {0}", pPath);

		for (const auto& shape : shapes)
		{
			for (const auto& index : shape.mesh.indices)
			{
				Vertex vertex;

				vertex.mPosition = { attrib.vertices[3 * index.vertex_index + 0], attrib.vertices[3 * index.vertex_index + 1], attrib.vertices[3 * index.vertex_index + 2] };
				vertex.mTexCoords = { attrib.texcoords[2 * index.texcoord_index + 0], attrib.texcoords[2 * index.texcoord_index + 1] };
				vertex.mNormal = { attrib.normals[3 * index.normal_index + 0], attrib.normals[3 * index.normal_index + 1], attrib.normals[3 * index.normal_index + 2] };

				mVertexBuffer.push_back(vertex);
				mIndexBuffer.push_back(mIndexBuffer.size());
			}
		}
	}

	MGLMaths::Mat4f Model::GetModelMatrix()
	{
		return MGLMaths::Mat4f::Transform(mPosition, mRotation, mScale);
	}

	void Model::Draw()
	{
		mBuffer.BindVao();

		glDrawArrays(GL_TRIANGLES, 0, mVertexBuffer.size());
		//glDrawElements(GL_TRIANGLES, mIndexBuffer.size(), GL_UNSIGNED_INT, nullptr);

		mBuffer.UnbindVao();
	}
}