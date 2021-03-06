#pragma once

#include "Core.h"

#include "Window.h"
#include "Sirius/Core/LayerStack.h"
#include "Sirius/Events/Event.h"
#include "Sirius/Events/ApplicationEvent.h"

#include "Sirius/Core/Timestep.h"

#include "Sirius/ImGui/ImGuiLayer.h"

namespace Sirius {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}


