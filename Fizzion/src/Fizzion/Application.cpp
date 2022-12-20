#include "Application.h"

#include "Fizzion/Events/ApplicationEvent.h"
#include "Fizzion/Log.h"
#include "fzpch.h"
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