#include <Sirius.h>

class ExampleLayer : public Sirius::Layer {
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SR_INFO("ExapleLayer::Update");
	}

	void OnEvent(Sirius::Event& event) override
	{
		SR_TRACE("{0}", event);
	}
};

class Sandbox : public Sirius::Application {
public:
	Sandbox() {
		//PushLayer(new ExampleLayer());
		PushOverlay(new Sirius::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Sirius::Application* Sirius::CreateApplication() {
	return new Sandbox();
}