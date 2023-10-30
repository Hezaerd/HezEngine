#pragma once

#include "HezEngine.hpp"

namespace HezEngine
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate(Timestep pStep) override;
		void OnEvent(Event& pEvent) override;

	private:
	};
}
