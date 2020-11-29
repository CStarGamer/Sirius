#pragma once

#include "Sirius/Layer.h"
#include "Sirius/Events/KeyEvent.h"
#include "Sirius/Events/MouseEvent.h"
#include "Sirius/Events/ApplicationEvent.h"

namespace Sirius {
	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		
		float m_Time = 0.0f;
	};

}

