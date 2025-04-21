#pragma once

// Platform detection
#ifdef _WIN32
    #ifdef _WIN64
        #define VOX_PLATFORM_WINDOWS
    #else
        #error "x86 builds are not supported!"
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #error "IOS simulator is not supported!"
    #elif TARGET_OS_IPHONE == 1
        #define VOX_PLATFORM_IOS
        #error "IOS is not supported!"
    #elif TARGET_OS_MAC == 1
        #define VOX_PLATFORM_MACOS
        #error "MacOS is not supported yet!"
    #else
        #error "Unknown Apple platform!"
    #endif
#elif defined(__ANDROID__)
    #define VOX_PLATFORM_ANDROID
    #error "Android is not supported yet!"
#elif defined(__linux__)
    #define VOX_PLATFORM_LINUX
    #error "Linux is not supported yet!"
#else
    #error "Unknown platform!"
#endif

// DLL export/import defines
#ifdef VOX_PLATFORM_WINDOWS
    #ifdef VOX_BUILD_DLL
        #define VOX_API __declspec(dllexport)
    #else
        #define VOX_API __declspec(dllimport)
    #endif
#else
    #error Vox only  support Windows!
#endif

#define BIT(x) (1 << x)
