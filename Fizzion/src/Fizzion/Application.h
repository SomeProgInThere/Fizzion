#pragma once

#include "Core.h"

namespace Fizzion
{
	class FIZZION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Should be defined in the Application
	Application* CreateApplication();
}