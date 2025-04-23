#pragma once

#ifdef VOX_PLATFORM_WINDOWS

extern Vox::Application* Vox::CreateApplication();

int main(int argc, char** argv)
{
    Vox::Log::Init();
    VOX_CORE_WARN("Initialized Log!");
    int a = 5;
    VOX_INFO("Hello! Var={0}", a);

    auto app = Vox::CreateApplication();
    app->Run();
    delete app;
}

#endif
