#pragma once

#ifdef _WIN32
    // Only define VOX_PLATFORM_WINDOWS if it's not already defined
    #ifndef VOX_PLATFORM_WINDOWS
        #define VOX_PLATFORM_WINDOWS
    #endif
    
    #ifdef VOX_BUILD_DLL
        #define VOX_API __declspec(dllexport)
    #else
        #define VOX_API __declspec(dllimport)
    #endif
#else
    #error Vox only supports Windows!
#endif

#define BIT(x) (1 << x)
