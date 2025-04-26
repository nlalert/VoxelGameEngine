#pragma once

#include "Core.h"

#include "Window.h"
#include "Vox/LayerStack.h"
#include "Vox/Events/Event.h"
#include "Vox/Events/ApplicationEvent.h"

namespace Vox {

    class VOX_API Application
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
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
    };

    //to be define in CLIENT
    Application* CreateApplication();
}

