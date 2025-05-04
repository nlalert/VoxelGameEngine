#pragma once

#include "Core.h"

#include "Window.h"
#include "Voxera/LayerStack.h"
#include "Voxera/Events/Event.h"
#include "Voxera/Events/ApplicationEvent.h"

#include "Voxera/ImGui/ImGuiLayer.h"

#include "Voxera/Renderer/Shader.h"
#include "Voxera/Renderer/Buffer.h"

namespace Voxera {

    class VXR_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

 		inline Window& GetWindow() { return *m_Window; }
 
 		inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
    private:
        static Application* s_Instance;
    };

    //to be define in CLIENT
    Application* CreateApplication();
}

