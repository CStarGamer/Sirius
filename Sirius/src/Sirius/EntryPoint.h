#pragma once

#ifdef SR_PLATFORM_WINDOWS
extern Sirius::Application* Sirius::CreateApplication();

int main(int argc, char** argv) {
	//---TEMPORARY---
	Sirius::Log::Init();
	SR_CORE_WARN("Core log initialized!");
	SR_INFO("Hello!");
	//---------------
	auto app = Sirius::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // SR_PLATFORM_WINDOWS


