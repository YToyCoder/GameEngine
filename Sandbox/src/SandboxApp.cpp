#include "GameEngine.h"

class Sandbox : public GameEngine::Application 
{
public:
	Sandbox(){}
	~Sandbox(){}

};

GameEngine::Application* GameEngine::createApplication() {
	return new Sandbox();
}
