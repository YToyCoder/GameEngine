#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::createApplication();

int main(int argc, char** argv) {
	GameEngine::Log::Init();
	HZ_CORE_WARN("init logger");
	HZ_CORE_INFO("welcome to GameEngine");
	auto app = GameEngine::createApplication();
	app->Run();
	delete app;
	return 0;
}

#endif

