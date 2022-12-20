#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Fizzion
{
	Application::Application() {}

	Application::~Application()	{}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		FZ_TRACE(e);

		while (true);
	}
}
