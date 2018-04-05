#error "DX11 UNIMPLEMENTED"

#define FX_DX(c) c

#if !defined(COBJMACROS)
#define COBJMACROS
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment (lib, "user32.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "d3dcompiler.lib")

static struct {
    uint64_t size;
    GLenum count;
    bool normalised;
    DXGI_FORMAT format;
    DXGI_FORMAT srv;
    DXGI_FORMAT dsv;
} _FX_GL45_FORMAT[] = {
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },

    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,             DXGI_FORMAT_BC1_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,             DXGI_FORMAT_BC2_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,             DXGI_FORMAT_BC3_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },

    { 1, 1, 1,           DXGI_FORMAT_R8_UNORM,              DXGI_FORMAT_R8_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 1, 1,           DXGI_FORMAT_R8_SNORM,              DXGI_FORMAT_R8_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 1, 0,            DXGI_FORMAT_R8_UINT,               DXGI_FORMAT_R8_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 1, 0,            DXGI_FORMAT_R8_SINT,               DXGI_FORMAT_R8_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 2, 1,         DXGI_FORMAT_R8G8_UNORM,            DXGI_FORMAT_R8G8_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 2, 1,         DXGI_FORMAT_R8G8_SNORM,            DXGI_FORMAT_R8G8_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 2, 0,          DXGI_FORMAT_R8G8_UINT,             DXGI_FORMAT_R8G8_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 2, 0,          DXGI_FORMAT_R8G8_SINT,             DXGI_FORMAT_R8G8_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 3, 1,       DXGI_FORMAT_R8G8B8_UNORM,          DXGI_FORMAT_R8G8B8_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 3, 1,       DXGI_FORMAT_R8G8B8_SNORM,          DXGI_FORMAT_R8G8B8_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 3, 0,        DXGI_FORMAT_R8G8B8_UINT,           DXGI_FORMAT_R8G8B8_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 3, 0,        DXGI_FORMAT_R8G8B8_SINT,           DXGI_FORMAT_R8G8B8_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 1,     DXGI_FORMAT_R8G8B8A8_UNORM,        DXGI_FORMAT_R8G8B8A8_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 1,     DXGI_FORMAT_R8G8B8A8_SNORM,        DXGI_FORMAT_R8G8B8A8_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 0,      DXGI_FORMAT_R8G8B8A8_UINT,         DXGI_FORMAT_R8G8B8A8_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 0,      DXGI_FORMAT_R8G8B8A8_SINT,         DXGI_FORMAT_R8G8B8A8_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 1,     DXGI_FORMAT_B8G8R8A8_UNORM,        DXGI_FORMAT_B8G8R8A8_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 1, 4, 1,     DXGI_FORMAT_B8G8R8A8_SNORM,        DXGI_FORMAT_B8G8R8A8_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },

    { 2, 1, 1,          DXGI_FORMAT_R16_UNORM,             DXGI_FORMAT_R16_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 1, 1,          DXGI_FORMAT_R16_SNORM,             DXGI_FORMAT_R16_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 1, 0,           DXGI_FORMAT_R16_UINT,              DXGI_FORMAT_R16_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 1, 0,           DXGI_FORMAT_R16_SINT,              DXGI_FORMAT_R16_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 1,       DXGI_FORMAT_R16G16_UNORM,          DXGI_FORMAT_R16G16_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 1,       DXGI_FORMAT_R16G16_SNORM,          DXGI_FORMAT_R16G16_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 0,        DXGI_FORMAT_R16G16_UINT,           DXGI_FORMAT_R16G16_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 0,        DXGI_FORMAT_R16G16_SINT,           DXGI_FORMAT_R16G16_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 3, 1,    DXGI_FORMAT_R16G16B16_UNORM,       DXGI_FORMAT_R16G16B16_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 3, 1,    DXGI_FORMAT_R16G16B16_SNORM,       DXGI_FORMAT_R16G16B16_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 3, 0,     DXGI_FORMAT_R16G16B16_UINT,        DXGI_FORMAT_R16G16B16_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 3, 0,     DXGI_FORMAT_R16G16B16_SINT,        DXGI_FORMAT_R16G16B16_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 1, DXGI_FORMAT_R16G16B16A16_UNORM,    DXGI_FORMAT_R16G16B16A16_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 1, DXGI_FORMAT_R16G16B16A16_SNORM,    DXGI_FORMAT_R16G16B16A16_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 0,  DXGI_FORMAT_R16G16B16A16_UINT,     DXGI_FORMAT_R16G16B16A16_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 0,  DXGI_FORMAT_R16G16B16A16_SINT,     DXGI_FORMAT_R16G16B16A16_SINT,           DXGI_FORMAT_UNKNOWN, },

    { 4, 1, 1,          DXGI_FORMAT_R32_UNORM,             DXGI_FORMAT_R32_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 1, 1,          DXGI_FORMAT_R32_SNORM,             DXGI_FORMAT_R32_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 1, 0,           DXGI_FORMAT_R32_UINT,              DXGI_FORMAT_R32_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 1, 0,           DXGI_FORMAT_R32_SINT,              DXGI_FORMAT_R32_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 1,       DXGI_FORMAT_R32G32_UNORM,          DXGI_FORMAT_R32G32_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 1,       DXGI_FORMAT_R32G32_SNORM,          DXGI_FORMAT_R32G32_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 0,        DXGI_FORMAT_R32G32_UINT,           DXGI_FORMAT_R32G32_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 0,        DXGI_FORMAT_R32G32_SINT,           DXGI_FORMAT_R32G32_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 1,    DXGI_FORMAT_R32G32B32_UNORM,       DXGI_FORMAT_R32G32B32_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 1,    DXGI_FORMAT_R32G32B32_SNORM,       DXGI_FORMAT_R32G32B32_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 0,     DXGI_FORMAT_R32G32B32_UINT,        DXGI_FORMAT_R32G32B32_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 0,     DXGI_FORMAT_R32G32B32_SINT,        DXGI_FORMAT_R32G32B32_SINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 4, 1, DXGI_FORMAT_R32G32B32A32_UNORM,    DXGI_FORMAT_R32G32B32A32_UNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 4, 1, DXGI_FORMAT_R32G32B32A32_SNORM,    DXGI_FORMAT_R32G32B32A32_SNORM,           DXGI_FORMAT_UNKNOWN, },
    { 4, 4, 0,  DXGI_FORMAT_R32G32B32A32_UINT,     DXGI_FORMAT_R32G32B32A32_UINT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 4, 0,  DXGI_FORMAT_R32G32B32A32_SINT,     DXGI_FORMAT_R32G32B32A32_SINT,           DXGI_FORMAT_UNKNOWN, },

    { 2, 1, 1,          DXGI_FORMAT_R16_FLOAT,             DXGI_FORMAT_R16_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 1, 0,          DXGI_FORMAT_R16_FLOAT,             DXGI_FORMAT_R16_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 1,       DXGI_FORMAT_R16G16_FLOAT,          DXGI_FORMAT_R16G16_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 2, 0,       DXGI_FORMAT_R16G16_FLOAT,          DXGI_FORMAT_R16G16_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 1, DXGI_FORMAT_R16G16B16A16_FLOAT,    DXGI_FORMAT_R16G16B16A16_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 2, 4, 0, DXGI_FORMAT_R16G16B16A16_FLOAT,    DXGI_FORMAT_R16G16B16A16_FLOAT,           DXGI_FORMAT_UNKNOWN, },

    { 4, 1, 1,          DXGI_FORMAT_R32_FLOAT,             DXGI_FORMAT_R32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 1, 0,          DXGI_FORMAT_R32_FLOAT,             DXGI_FORMAT_R32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 1,       DXGI_FORMAT_R32G32_FLOAT,          DXGI_FORMAT_R32G32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 2, 0,       DXGI_FORMAT_R32G32_FLOAT,          DXGI_FORMAT_R32G32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 1,    DXGI_FORMAT_R32G32B32_FLOAT,       DXGI_FORMAT_R32G32B32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 4, 3, 0,    DXGI_FORMAT_R32G32B32_FLOAT,       DXGI_FORMAT_R32G32B32_FLOAT,           DXGI_FORMAT_UNKNOWN, },
    { 0, 0, 0,            DXGI_FORMAT_UNKNOWN,               DXGI_FORMAT_UNKNOWN,           DXGI_FORMAT_UNKNOWN, },
    { 4, 4, 0, DXGI_FORMAT_R32G32B32A32_FLOAT,    DXGI_FORMAT_R32G32B32A32_FLOAT,           DXGI_FORMAT_UNKNOWN, },

    { 2, 1, 1,       DXGI_FORMAT_R16_TYPELESS,             DXGI_FORMAT_R16_UNORM,         DXGI_FORMAT_D16_UNORM, },
    { 4, 1, 1,     DXGI_FORMAT_R24G8_TYPELESS, DXGI_FORMAT_R24_UNORM_X8_TYPELESS, DXGI_FORMAT_D24_UNORM_S8_UINT, },
    { 4, 1, 1,       DXGI_FORMAT_R32_TYPELESS,             DXGI_FORMAT_R32_FLOAT,         DXGI_FORMAT_D32_FLOAT, },
};

struct fxBackendBuffer {
    IDX3D11Buffer* name;
    uint32_t flags;
    uint32_t size;
};

struct fxBackendTexture {
    void* name;
    ID3D11Texture2D* name_2d;
    ID3D11Texture3D* name_3d;
    uint32_t flags;
    uint32_t type;
    uint32_t format;
};

struct fxBackendSampler {
    ID3D11SamplerState* name;
    uint32_t flags;
};

struct fxBackendShader {
    uint32_t name;

    void* _;
};

typedef struct fxBackendProgram {
    uint32_t name;
    struct {
        uint32_t name;
    } stages[FX_SHADER_STAGE_COUNT];
} fxBackendProgram;

struct fxBackendPass {
    uint32_t name;
    uint32_t count;

    void* _;
};

struct fxBackendRenderTarget {
    uint32_t name;

    void* _;
};

struct fxBackendPipeline {
    ID3D11InputLayout* layouts[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    ID3D11BlendState* blend;
    ID3D11RasterizerState* raster;
    ID3D11DepthStencilState* depth_stencil;
};

struct fxBackendCtx {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    fxPoolAllocator pipeline_allocator;
    fxPoolAllocator render_target_allocator;
    fxPoolAllocator buffer_allocator;
    fxPoolAllocator shader_allocator;
    fxPoolAllocator texture_allocator;
    fxPoolAllocator sampler_allocator;
    fxPoolAllocator pass_allocator;

    fxBackendPipeline pipelines[FX_CONFIG_PIPELINE_MAX];
    fxBackendRenderTarget render_targets[FX_CONFIG_RENDER_TARGET_MAX];
    fxBackendBuffer buffers[FX_CONFIG_BUFFER_MAX];
    fxBackendShader shaders[FX_CONFIG_SHADER_MAX];
    fxBackendTexture textures[FX_CONFIG_TEXTURE_MAX];
    fxBackendSampler samplers[FX_CONFIG_TEXTURE_MAX];
    fxBackendPass passes[FX_CONFIG_PASS_MAX];

    fxBackendPass default_pass;

    struct {
    } cache;
};

fxBackendCtx* fx_backend(fxCfg* cfg, fxBackendApi* api) {
    fxBackendCtx* res = (fxBackendCtx*) FX_MALLOC(sizeof(fxBackendCtx));
    FX_MEMSET(res, 0, sizeof(fxBackendCtx));

    res->buffer_allocator = fx_pool_allocator(res->buffers, FX_CONFIG_BUFFER_MAX, sizeof(fxBackendBuffer));
    res->pass_allocator = fx_pool_allocator(res->passes, FX_CONFIG_PASS_MAX, sizeof(fxBackendPass));
    res->pipeline_allocator = fx_pool_allocator(res->pipelines, FX_CONFIG_PIPELINE_MAX, sizeof(fxBackendPipeline));
    res->render_target_allocator = fx_pool_allocator(res->render_targets, FX_CONFIG_RENDER_TARGET_MAX, sizeof(fxBackendRenderTarget));
    res->sampler_allocator = fx_pool_allocator(res->samplers, FX_CONFIG_TEXTURE_MAX, sizeof(fxBackendSampler));
    res->shader_allocator = fx_pool_allocator(res->shaders, FX_CONFIG_SHADER_MAX, sizeof(fxBackendShader));
    res->texture_allocator = fx_pool_allocator(res->textures, FX_CONFIG_TEXTURE_MAX, sizeof(fxBackendTexture));

    {
        DXGI_SWAP_CHAIN_DESC cfg;
        cfg.BufferCount = 1;
        cfg.BufferDesc.Width = 640;
        cfg.BufferDesc.Height = 480;
        cfg.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        cfg.BufferDesc.RefreshRate = (DXGI_RATIONAL){59951, 1000};
        cfg.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        cfg.OutputWindow = GetActiveWindow();
        cfg.SampleDesc.Count = 1;
        cfg.SampleDesc.Quality = 0;
        cfg.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        cfg.Windowed = TRUE;
        UINT flags = D3D11_CREATE_DEVICE_DEBUG;

        D3D_FEATURE_LEVEL levels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1,
                                      D3D_FEATURE_LEVEL_10_0, D3D_FEATURE_LEVEL_9_3,  D3D_FEATURE_LEVEL_9_2,
                                      D3D_FEATURE_LEVEL_9_1};
        D3D_FEATURE_LEVEL level;

        HRESULT hr = D3D11CreateDeviceAndSwapChain(
            NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, flags, levels, FX_COUNT_OF(levels), D3D11_SDK_VERSION, &cfg,
            &res->swap_chain, &res->device, &level, &res->ctx);
        if(hr == E_INVALIDARG) {
            hr = D3D11CreateDeviceAndSwapChain(
                NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, flags, &levels[1], FX_COUNT_OF(levels) - 1, D3D11_SDK_VERSION,
                &cfg, &res->swap_chain, &res->device, &level, &res->ctx);
        }
        FX_ASSERT(SUCCEEDED(hr));

        hr = res->swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*) &res->default_pass.texture);
        FX_ASSERT(SUCCEEDED(hr));
        hr = res->device->CreateRenderTargetView(res->default_pass.texture, NULL, &res->default_pass.rtv);
        FX_ASSERT(SUCCEEDED(hr));
        float colour[4] = {1.0f, 0.0f, 0.0f, 1.0f};
        res->ctx->ClearRenderTargetView(res->default_pass.rtv, colour);
        res->swap_chain->Present(1, 0);
    }
    return res;
}

/*
 * ---------------------------------- LICENSE ----------------------------------
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org>
 * =============================================================================
 */
