#pragma once

#include "HezEngine/Core/Layer.hpp"

#include "HezEngine/Events/AppEvent.hpp"
#include "HezEngine/Events/KeyEvent.hpp"
#include "HezEngine/Events/MouseEvent.hpp"

namespace HezEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& e) override;

		//void OnImGuiRender() override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

		uint32_t GetActiveID() const;
	private:
		bool m_BlockEvents = true;
	};
}