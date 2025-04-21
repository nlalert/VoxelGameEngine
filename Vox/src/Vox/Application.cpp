#include "Application.h"

#include "Vox/Events/ApplicationEvent.h"
#include "Vox/Log.h"

namespace Vox {

    Application::Application()
    {
    }
    
    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
 		if (e.IsInCategory(EventCategoryApplication))
 		{
 			VOX_TRACE(e.ToString());
 		}
 		if (e.IsInCategory(EventCategoryInput))
 		{
 			VOX_TRACE(e.ToString());
 		}
 
        while(true);
    }

}
