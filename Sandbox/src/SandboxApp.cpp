#include <Fizzion.h>

class Sandbox : public Fizzion::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Fizzion::Application* Fizzion::CreateApplication()
{
	return new Sandbox();
}
	