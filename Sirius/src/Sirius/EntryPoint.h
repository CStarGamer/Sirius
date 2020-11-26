#pragma once

#ifdef SR_PLATFORM_WINDOWS
extern Sirius::Application* Sirius::CreateApplication();

int main(int argc, char** argv) {
	printf("Running App...");
	auto app = Sirius::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // SR_PLATFORM_WINDOWS
