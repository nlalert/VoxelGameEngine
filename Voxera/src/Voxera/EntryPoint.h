#pragma once

#ifdef VXR_PLATFORM_WINDOWS

extern Voxera::Application* Voxera::CreateApplication();

int main(int argc, char** argv)
{
    Voxera::Log::Init();
    VXR_CORE_WARN("Initialized Log!");
    int a = 5;
    VXR_INFO("Hello! Var={0}", a);

    auto app = Voxera::CreateApplication();
    app->Run();
    delete app;
}

#endif
