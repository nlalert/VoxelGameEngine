#include <Vox.h>

class Sandbox : public Vox::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }

};

Vox::Application* Vox::CreateApplication()
{
    return new Sandbox();
}
