#pragma once

#ifdef SR_PLATFORM_WINDOWS
// extern Sirius::Application* Sirius::CreateApplication();

int main(int argc, char** argv) {
	//---TEMPORARY---
	Sirius::Log::Init();
	//---------------
	auto app = Sirius::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // SR_PLATFORM_WINDOWS


