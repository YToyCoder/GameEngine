#pragma once
#include "Core.h"
namespace GameEngine {
	class HAZEL_API Application 
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//
	Application* createApplication();

}
