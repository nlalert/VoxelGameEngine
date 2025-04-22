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

#ifdef VOX_ENABLE_ASSERTS
 	#define VOX_ASSERT(x, ...) { if(!(x)) { VOX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
 	#define VOX_CORE_ASSERT(x, ...) { if(!(x)) { VOX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
 #else
 	#define VOX_ASSERT(x, ...)
 	#define VOX_CORE_ASSERT(x, ...)
 #endif

#define BIT(x) (1 << x)
