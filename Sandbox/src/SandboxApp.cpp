#include <Voxera.h>

#include "imgui/imgui.h"

class ExampleLayer : public Voxera::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        if (Voxera::Input::IsKeyPressed(VXR_KEY_TAB))
        {
            VXR_TRACE("Tab Key is Pressed!");
        }
    }

    void OnEvent(Voxera::Event& event) override
    {
        // VXR_TRACE("{0}", event.ToString());
    }

};
 
class Sandbox : public Voxera::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }

};

Voxera::Application* Voxera::CreateApplication()
{
    return new Sandbox();
}
