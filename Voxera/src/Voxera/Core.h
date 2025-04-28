#pragma once

#ifdef _WIN32
    // Only define VXR_PLATFORM_WINDOWS if it's not already defined
    #ifndef VXR_PLATFORM_WINDOWS
        #define VXR_PLATFORM_WINDOWS
    #endif
    
    #ifdef VXR_BUILD_DLL
        #define VXR_API __declspec(dllexport)
    #else
        #define VXR_API __declspec(dllimport)
    #endif
#else
    #error Voxera only supports Windows!
#endif

#ifdef VXR_DEBUG
    #define VXR_ENABLE_ASSERTS
#endif

#ifdef VXR_ENABLE_ASSERTS
 	#define VXR_ASSERT(x, ...) { if(!(x)) { VXR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
 	#define VXR_CORE_ASSERT(x, ...) { if(!(x)) { VXR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
 #else
 	#define VXR_ASSERT(x, ...)
 	#define VXR_CORE_ASSERT(x, ...)
 #endif

#define BIT(x) (1 << x)

#define VXR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
