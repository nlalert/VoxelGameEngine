#pragma once
 
#include "Voxera/Layer.h"

#include "Voxera/Events/ApplicationEvent.h"
#include "Voxera/Events/KeyEvent.h"
#include "Voxera/Events/MouseEvent.h"

namespace Voxera {

    class VXR_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override; 
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };

}
