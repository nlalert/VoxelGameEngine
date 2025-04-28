#pragma once 

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Voxera{

    class VXR_API Log
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
#define VXR_CORE_TRACE(...)  ::Voxera::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VXR_CORE_INFO(...)   ::Voxera::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VXR_CORE_WARN(...)   ::Voxera::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VXR_CORE_ERROR(...)  ::Voxera::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VXR_CORE_FATAL(...)  ::Voxera::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VXR_TRACE(...)       ::Voxera::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VXR_INFO(...)        ::Voxera::Log::GetClientLogger()->info(__VA_ARGS__)
#define VXR_WARN(...)        ::Voxera::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VXR_ERROR(...)       ::Voxera::Log::GetClientLogger()->error(__VA_ARGS__)
#define VXR_FATAL(...)       ::Voxera::Log::GetClientLogger()->fatal(__VA_ARGS__)
