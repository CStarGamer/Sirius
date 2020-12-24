#pragma once

#include "Core.h"

#include "Window.h"
#include "Sirius/LayerStack.h"
#include "Sirius/Events/Event.h"
#include "Sirius/Events/ApplicationEvent.h"

#include "Sirius/ImGui/ImGuiLayer.h"

#include "Sirius/Renderer/Shader.h"
#include "Sirius/Renderer/Buffer.h"
#include "Sirius/Renderer/VertexArray.h"

#include "Sirius/Renderer/OrthographicCamera.h"

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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}


