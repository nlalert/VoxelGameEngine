#include <Voxera.h>

class ExampleLayer : public Voxera::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        VXR_INFO("ExampleLayer::Update");
    }

    void OnEvent(Voxera::Event& event) override
    {
        VXR_TRACE("{0}", event.ToString());
    }

};
 
class Sandbox : public Voxera::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Voxera::ImGuiLayer());
    }

    ~Sandbox()
    {

    }

};

Voxera::Application* Voxera::CreateApplication()
{
    return new Sandbox();
}
