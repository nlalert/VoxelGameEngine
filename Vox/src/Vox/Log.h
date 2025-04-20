#pragma once 

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vox{

    class VOX_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define VOX_CORE_TRACE(...)  ::Vox::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VOX_CORE_INFO(...)   ::Vox::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VOX_CORE_WARN(...)   ::Vox::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VOX_CORE_ERROR(...)  ::Vox::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VOX_CORE_FATAL(...)  ::Vox::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VOX_TRACE(...)       ::Vox::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VOX_INFO(...)        ::Vox::Log::GetClientLogger()->info(__VA_ARGS__)
#define VOX_WARN(...)        ::Vox::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VOX_ERROR(...)       ::Vox::Log::GetClientLogger()->error(__VA_ARGS__)
#define VOX_FATAL(...)       ::Vox::Log::GetClientLogger()->fatal(__VA_ARGS__)
