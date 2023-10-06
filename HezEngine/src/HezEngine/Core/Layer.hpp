#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Events/Event.hpp"
#include "HezEngine/Core/Timestep.hpp"

namespace HezEngine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Default");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep /*pStep*/) {}
		virtual void OnEvent(Event& /*event*/) {}

		const std::string& GetName() const { return m_name; }

	protected:
		std::string m_name;
	};
}