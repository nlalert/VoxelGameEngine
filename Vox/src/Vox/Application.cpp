#include "voxpch.h"
#include "Application.h"

#include "Vox/Log.h"

#include <GLFW/glfw3.h>

namespace Vox {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback([this](Event& e) { OnEvent(e); });
    }
    
    Application::~Application()
    {
    }

	void Application::OnEvent(Event& e)
 	{
 		EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) { return OnWindowClose(e); });
 
 		VOX_CORE_TRACE("{0}", e.ToString());
 	}

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

	bool Application::OnWindowClose(WindowCloseEvent& e)
 	{
 		m_Running = false;
 		return true;
 	}
}
