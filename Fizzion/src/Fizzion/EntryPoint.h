#pragma once

#ifdef FZ_PLATFORM_VALIDATE

extern Fizzion::Application* Fizzion::CreateApplication();

int main(int argc, char** argv)
{
	Fizzion::Log::Init();
	FZ_CORE_WARN("Initializing Logger...");
	FZ_INFO("Hello from Fizzion!");

	auto app = Fizzion::CreateApplication();
	app->Run();
	delete app;
}

#endif 
