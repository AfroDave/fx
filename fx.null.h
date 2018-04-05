typedef struct fxNullBuffer {
    uintptr_t _;

    fxBufferId id;
} fxNullBuffer;

typedef struct fxNullTexture {
    uintptr_t _;

    fxTextureId id;
} fxNullTexture;

typedef struct fxNullSampler {
    uintptr_t _;

    fxSamplerId id;
} fxNullSampler;

typedef struct fxNullShader {
    uintptr_t _;

    fxShaderId id;
} fxNullShader;

typedef struct fxNullPass {
    uintptr_t _;

    fxPassId id;
} fxNullPass;

typedef struct fxNullPipeline {
    uintptr_t _;

    fxPipelineId id;
} fxNullPipeline;

struct fxBackendCtx {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    fxPoolAllocator pipeline_allocator;
    fxPoolAllocator buffer_allocator;
    fxPoolAllocator shader_allocator;
    fxPoolAllocator texture_allocator;
    fxPoolAllocator sampler_allocator;
    fxPoolAllocator pass_allocator;

    fxNullPipeline pipelines[FX_CONFIG_PIPELINE_MAX];
    fxNullBuffer buffers[FX_CONFIG_BUFFER_MAX];
    fxNullShader shaders[FX_CONFIG_SHADER_MAX];
    fxNullTexture textures[FX_CONFIG_TEXTURE_MAX];
    fxNullSampler samplers[FX_CONFIG_TEXTURE_MAX];
    fxNullPass passes[FX_CONFIG_PASS_MAX];
};

static void _fx_backend_destroy(fxBackendCtx* ctx) {
    FX_ASSERT(ctx != NULL);
    FX_FREE(ctx);
}

static fxPipelineId _fx_backend_pipeline(fxBackendCtx* ctx, fxPipelineCfg* cfg) {
    (void) cfg;
    FX_ASSERT(ctx != NULL);
    fxNullPipeline* pipeline = (fxNullPipeline*) _fx_pool_allocator_alloc(&ctx->pipeline_allocator);
    FX_ASSERT(pipeline != NULL);

    fxPipelineId id = FX_ID(FX_INDEX_FROM_PTR(pipeline, ctx->pipelines), FX_ID_GENERATION(pipeline->id) + 1, FX_ID_KIND_PIPELINE);
    pipeline->id = id;
    return id;
}

static void _fx_backend_pipeline_destroy(fxBackendCtx* ctx, fxPipelineId pipeline) {
    FX_ASSERT(ctx != NULL);
    fxNullPipeline* pipeline_ptr = FX_PTR_FROM_ID(ctx->pipelines, pipeline);
    _fx_pool_allocator_dealloc(&ctx->pipeline_allocator, pipeline_ptr);
}

static fxBufferId _fx_backend_buffer(fxBackendCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size) {
    (void) cfg;
    (void) data;
    (void) size;
    FX_ASSERT(ctx != NULL);
    fxNullBuffer* buffer = (fxNullBuffer*) _fx_pool_allocator_alloc(&ctx->buffer_allocator);
    FX_ASSERT(buffer != NULL);
    FX_ASSERT(size <= cfg->size);

    fxBufferId id = FX_ID(FX_INDEX_FROM_PTR(buffer, ctx->buffers), FX_ID_GENERATION(buffer->id) + 1, FX_ID_KIND_BUFFER);
    buffer->id = id;
    return id;
}

static void _fx_backend_buffer_destroy(fxBackendCtx* ctx, fxBufferId buffer) {
    FX_ASSERT(ctx != NULL);
    fxNullBuffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    _fx_pool_allocator_dealloc(&ctx->buffer_allocator, buffer_ptr);
}

static void _fx_backend_buffer_update(fxBackendCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset) {
    (void) data;
    (void) size;
    (void) offset;
    FX_ASSERT(ctx != NULL);
    fxNullBuffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    FX_ASSERT(buffer == buffer_ptr->id);
}

static fxTextureId _fx_backend_texture(fxBackendCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes) {
    (void) cfg;
    (void) datas;
    (void) sizes;
    FX_ASSERT(ctx != NULL);
    fxNullTexture* texture = (fxNullTexture*) _fx_pool_allocator_alloc(&ctx->texture_allocator);
    FX_ASSERT(texture != NULL);

    fxTextureId id = FX_ID(FX_INDEX_FROM_PTR(texture, ctx->textures), FX_ID_GENERATION(texture->id) + 1, FX_ID_KIND_TEXTURE);
    texture->id = id;
    return id;
}

static void _fx_backend_texture_destroy(fxBackendCtx* ctx, fxTextureId texture) {
    FX_ASSERT(ctx != NULL);
    fxNullTexture* texture_ptr = FX_PTR_FROM_ID(ctx->textures, texture);
    _fx_pool_allocator_dealloc(&ctx->texture_allocator, texture_ptr);
}

static void _fx_backend_texture_update(fxBackendCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region) {
    (void) texture;
    (void) data;
    (void) region;
    FX_ASSERT(ctx != NULL);
}

static fxSamplerId _fx_backend_sampler(fxBackendCtx* ctx, fxSamplerCfg* cfg) {
    (void) cfg;
    FX_ASSERT(ctx != NULL);
    fxNullSampler* sampler = (fxNullSampler*) _fx_pool_allocator_alloc(&ctx->sampler_allocator);
    FX_ASSERT(sampler != NULL);

    fxSamplerId id = FX_ID(FX_INDEX_FROM_PTR(sampler, ctx->samplers), FX_ID_GENERATION(sampler->id) + 1, FX_ID_KIND_SAMPLER);
    sampler->id = id;
    return id;
}

static void _fx_backend_sampler_destroy(fxBackendCtx* ctx, fxSamplerId sampler) {
    FX_ASSERT(ctx != NULL);
    fxNullSampler* sampler_ptr = FX_PTR_FROM_ID(ctx->samplers, sampler);
    _fx_pool_allocator_dealloc(&ctx->sampler_allocator, sampler_ptr);
}

static fxPassId _fx_backend_pass(fxBackendCtx* ctx, fxPassCfg* cfg) {
    (void) cfg;
    FX_ASSERT(ctx != NULL);
    fxNullPass* pass = (fxNullPass*) _fx_pool_allocator_alloc(&ctx->pass_allocator);
    FX_ASSERT(pass != NULL);

    fxPassId id = FX_ID(FX_INDEX_FROM_PTR(pass, ctx->passes), FX_ID_GENERATION(pass->id) + 1, FX_ID_KIND_PASS);
    pass->id = id;
    return id;
}

static void _fx_backend_pass_destroy(fxBackendCtx* ctx, fxPassId pass) {
    FX_ASSERT(ctx != NULL);
    fxNullPass* pass_ptr = FX_PTR_FROM_ID(ctx->passes, pass);
    _fx_pool_allocator_dealloc(&ctx->pass_allocator, pass_ptr);
}

static fxShaderId _fx_backend_shader(fxBackendCtx* ctx, fxShaderCfg* cfg) {
    (void) cfg;
    FX_ASSERT(ctx != NULL);
    fxNullShader* shader = (fxNullShader*) _fx_pool_allocator_alloc(&ctx->shader_allocator);
    FX_ASSERT(shader != NULL);

    fxShaderId id = FX_ID(FX_INDEX_FROM_PTR(shader, ctx->shaders), FX_ID_GENERATION(shader->id) + 1, FX_ID_KIND_SHADER);
    shader->id = id;
    return id;
}

static void _fx_backend_shader_destroy(fxBackendCtx* ctx, fxShaderId shader) {
    FX_ASSERT(ctx != NULL);
    fxNullShader* shader_ptr = FX_PTR_FROM_ID(ctx->shaders, shader);
    _fx_pool_allocator_dealloc(&ctx->shader_allocator, shader_ptr);
}

static void _fx_backend_submit(fxBackendCtx* ctx, fxCmdBuffer* cmd_buffer) {
    FX_ASSERT(ctx != NULL);
    (void) ctx;
    (void) cmd_buffer;
}

static void* _fx_backend(fxCfg* cfg, fxSystemInfo* info) {
    fxBackendCtx* res = (fxBackendCtx*) FX_MALLOC(sizeof(fxBackendCtx));
    FX_ASSERT(res != NULL);
    FX_MEMSET(res, 0, sizeof(fxBackendCtx));

    res->usr = cfg->usr;
    res->log = cfg->log;

    res->buffer_allocator = _fx_pool_allocator(res->buffers, FX_CONFIG_BUFFER_MAX, sizeof(fxNullBuffer));
    res->pass_allocator = _fx_pool_allocator(res->passes, FX_CONFIG_PASS_MAX, sizeof(fxNullPass));
    res->pipeline_allocator = _fx_pool_allocator(res->pipelines, FX_CONFIG_PIPELINE_MAX, sizeof(fxNullPipeline));
    res->sampler_allocator = _fx_pool_allocator(res->samplers, FX_CONFIG_TEXTURE_MAX, sizeof(fxNullSampler));
    res->shader_allocator = _fx_pool_allocator(res->shaders, FX_CONFIG_SHADER_MAX, sizeof(fxNullShader));
    res->texture_allocator = _fx_pool_allocator(res->textures, FX_CONFIG_TEXTURE_MAX, sizeof(fxNullTexture));

    if(info) {
        info->api = "fx null";
        info->version = "0";
        info->device = "null";
        info->vendor = "null";
        info->shading_language = "null";
        info->texture_copy_support = false;
        info->geometry_shader_support = false;
        info->tessellation_shader_support = false;
        info->compute_shader_support = false;
        info->max_texture_size = 0;
        info->max_texture_array_count = 0;
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
