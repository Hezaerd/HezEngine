#pragma once

#include "HezEngine/Core/Layer.hpp"

namespace HezEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		virtual void Begin() = 0;
		virtual void End() = 0;

		void SetDarkThemeColors();

		static ImGuiLayer* Create();

	private:
	};
}
