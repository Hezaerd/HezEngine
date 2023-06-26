#pragma once

#include "MinecraftGL/Core/Base.hpp"
#include "MinecraftGL/Events/Event.hpp"

namespace MinecraftGL
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Default");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_name; }

	protected:
		std::string m_name;
	};
}