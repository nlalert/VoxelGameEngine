#include <Vox.h>

class ExampleLayer : public Vox::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        VOX_INFO("ExampleLayer::Update");
    }

    void OnEvent(Vox::Event& event) override
    {
        VOX_TRACE("{0}", event.ToString());
    }

};
 
class Sandbox : public Vox::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Vox::ImGuiLayer());
    }

    ~Sandbox()
    {

    }

};

Vox::Application* Vox::CreateApplication()
{
    return new Sandbox();
}
