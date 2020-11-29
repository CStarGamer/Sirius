#include <Sirius.h>

class ExampleLayer : public Sirius::Layer {
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//SR_INFO("ExapleLayer::Update");

		if (Sirius::Input::IsKeyPressed(SR_KEY_TAB))
			SR_TRACE("Tab is pressed!");
	}

	void OnEvent(Sirius::Event& event) override
	{
		//SR_TRACE("{0}", event);
		if (event.GetEventType() == Sirius::EventType::KeyPressed)
		{
			Sirius::KeyPressedEvent& e = (Sirius::KeyPressedEvent&)event;
			SR_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Sirius::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Sirius::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Sirius::Application* Sirius::CreateApplication() {
	return new Sandbox();
}