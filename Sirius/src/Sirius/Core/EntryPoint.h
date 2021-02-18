#pragma once

#ifdef SR_PLATFORM_WINDOWS
// extern Sirius::Application* Sirius::CreateApplication();

int main(int argc, char** argv) {
	//---TEMPORARY---
	Sirius::Log::Init();
	//---------------
	SR_PROFILE_BEGIN_SESSION("Startup", "SiriusProfile-Startup.json");
	auto app = Sirius::CreateApplication();
	SR_PROFILE_END_SESSION();

	SR_PROFILE_BEGIN_SESSION("Runtime", "SiriusProfile-Runtime.json");
	app->Run();
	SR_PROFILE_END_SESSION();

	SR_PROFILE_BEGIN_SESSION("Shutdown", "SiriusProfile-Shutdown.json");
	delete app;
	SR_PROFILE_END_SESSION();

	return 0;
}
#endif // SR_PLATFORM_WINDOWS


