#include "srpch.h"
#include "Application.h"
#include "Sirius/Events/ApplicationEvent.h"
#include "Sirius/Log.h"

namespace Sirius {

	Application::Application() {

	}
	Application::~Application() {

	}
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.isInCategory(EventCategoryApplication))
		{
			SR_TRACE(e);
		}
		if (e.isInCategory(EventCategoryInput))
		{
			SR_TRACE(e);
		}

		while (true);
	}
}