#include "vxrpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Voxera {

    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RenderAPI::None:    VXR_ASSERT(false, "RenderAPI::None is not support"); return nullptr;
            case RenderAPI::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
        }

        VXR_ASSERT(false, "Unknow Render API");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RenderAPI::None:    VXR_ASSERT(false, "RenderAPI::None is not support"); return nullptr;
            case RenderAPI::OpenGL:  return new OpenGLIndexBuffer(indices, size);
        }

        VXR_ASSERT(false, "Unknow Render API");
        return nullptr;
    }
}
