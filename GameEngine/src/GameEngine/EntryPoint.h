#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::createApplication();

int main(int argc, char** argv) {
	auto app = GameEngine::createApplication();
	app->Run();
	delete app;
	return 0;
}

#endif

