/*
 * `fx.h`
 *
 * usage:
 *      #define FX_IMPL
 *      #include "fx.h"
 */

#if !defined(FX_H)
#define FX_H

#define FX_VERSION_MAJOR 0
#define FX_VERSION_MINOR 13
#define FX_VERSION_PATCH 1

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdbool.h>

#if defined(_MSC_VER)
#if _MSC_VER < 1300
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
#else
typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
#endif
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#if defined(FX_STATIC)
#define FX_API static
#else
#define FX_API extern
#endif

#if defined(__GNUC__)
#define FX_DEPRECATED __attribute__((deprecated))
#elif defined(_WIN32)
#define FX_DEPRECATED __declspec(deprecated)
#else
#define FX_DEPRECATED
#endif

#define FX_ALL ((uint32_t) -1)

#define FX_CONFIG_CMD_BUFFER_MAX (8)
#define FX_CONFIG_CMD_BUFFER_CMD_MAX (1024 * 8)
#define FX_CONFIG_RENDER_TARGET_MAX (32)
#define FX_CONFIG_TEXTURE_MAX (128)
#define FX_CONFIG_BUFFER_MAX (128)
#define FX_CONFIG_VERTEX_BUFFER_BINDING_MAX (8)
#define FX_CONFIG_UNIFORM_BUFFER_BINDING_MAX (4)
#define FX_CONFIG_TEXTURE_BINDING_MAX (4)
#define FX_CONFIG_SHADER_MAX (64)
#define FX_CONFIG_PIPELINE_MAX (32)
#define FX_CONFIG_PASS_MAX (16)
#define FX_CONFIG_ATTACHMENT_MAX (8)

typedef struct fxCtxT* fxCtx;
typedef struct fxCmdBufferT* fxCmdBuffer;
typedef struct fxBackendPass* fxPass;
typedef struct fxBackendRenderTarget* fxRenderTarget;
typedef struct fxBackendShader* fxShader;
typedef struct fxBackendPipeline* fxPipeline;
typedef struct fxBackendBuffer* fxBuffer;
typedef struct fxBackendTexture* fxTexture;
typedef struct fxBackendSampler* fxSampler;

typedef void (*fxFn)(void);

enum {
    // fxBufferCfg flags
    FX_BUFFER_DYNAMIC = 1 << 0,

    // fxTextureCfg flags
    FX_TEXTURE_MULTISAMPLE = 1 << 0,

    // fxSamplerCfg flags
    FX_SAMPLER_COMPARE = 1 << 0,

    // fxPipelineBlendCfg flags
    FX_PIPELINE_BLEND = 1 << 0,
    FX_PIPELINE_BLEND_LOGIC = 1 << 1,
    FX_WRITE_COLOUR = 1 << 0,
    FX_WRITE_ALPHA = 1 << 1,
    FX_WRITE_DEPTH = 1 << 2,

    // fxPipelineBlendCfg colour_mask
    FX_COLOUR_MASK_R = 1 << 0,
    FX_COLOUR_MASK_G = 1 << 1,
    FX_COLOUR_MASK_B = 1 << 2,
    FX_COLOUR_MASK_A = 1 << 3,

    // fxPipelineDepthStencilCfg flags
    FX_PIPELINE_DEPTH_STENCIL_DEPTH_TEST = 1 << 0,
    FX_PIPELINE_DEPTH_STENCIL_DEPTH_WRITE = 1 << 1,
    FX_PIPELINE_DEPTH_STENCIL_DEPTH_BOUNDS_TEST = 1 << 2,
    FX_PIPELINE_DEPTH_STENCIL_STENCIL_TEST = 1 << 3,

    // fxPipelineRasterCfg flags
    FX_PIPELINE_RASTER_DEPTH_CLAMP = 1 << 0,
    FX_PIPELINE_RASTER_SCISSOR_TEST = 1 << 1,
    FX_PIPELINE_RASTER_ALPHA_TO_COVERAGE = 1 << 2
};

typedef enum fxCompareOp {
    FX_COMPARE_OP_ALWAYS,
    FX_COMPARE_OP_LESS,
    FX_COMPARE_OP_LEQUAL,
    FX_COMPARE_OP_EQUAL,
    FX_COMPARE_OP_NOTEQUAL,
    FX_COMPARE_OP_GREATER,
    FX_COMPARE_OP_GEQUAL,
    FX_COMPARE_OP_NEVER
} fxCompareOp;

typedef enum fxBlendFactor {
    FX_BLEND_FACTOR_ZERO,
    FX_BLEND_FACTOR_ONE,
    FX_BLEND_FACTOR_SRC_COLOR,
    FX_BLEND_FACTOR_ONE_MINUS_SRC_COLOR,
    FX_BLEND_FACTOR_DST_COLOR,
    FX_BLEND_FACTOR_ONE_MINUS_DST_COLOR,
    FX_BLEND_FACTOR_SRC_ALPHA,
    FX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
    FX_BLEND_FACTOR_DST_ALPHA,
    FX_BLEND_FACTOR_ONE_MINUS_DST_ALPHA,
    FX_BLEND_FACTOR_CONSTANT_COLOR,
    FX_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
    FX_BLEND_FACTOR_CONSTANT_ALPHA,
    FX_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
    FX_BLEND_FACTOR_SRC_ALPHA_SATURATE,
    FX_BLEND_FACTOR_SRC1_COLOR,
    FX_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR,
    FX_BLEND_FACTOR_SRC1_ALPHA,
    FX_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA
} fxBlendFactor;

typedef enum fxBlendOp {
    FX_BLEND_OP_ADD,
    FX_BLEND_OP_SUB,
    FX_BLEND_OP_INV_SUB,
    FX_BLEND_OP_MIN,
    FX_BLEND_OP_MAX
} fxBlendOp;

typedef enum fxLogicOp {
    FX_LOGIC_OP_COPY,
    FX_LOGIC_OP_NOOP,
    FX_LOGIC_OP_CLEAR,
    FX_LOGIC_OP_AND,
    FX_LOGIC_OP_AND_REVERSE,
    FX_LOGIC_OP_AND_INVERTED,
    FX_LOGIC_OP_XOR,
    FX_LOGIC_OP_OR,
    FX_LOGIC_OP_NOR,
    FX_LOGIC_OP_EQUIVALENT,
    FX_LOGIC_OP_INVERT,
    FX_LOGIC_OP_OR_REVERSE,
    FX_LOGIC_OP_COPY_INVERTED,
    FX_LOGIC_OP_OR_INVERTED,
    FX_LOGIC_OP_NAND,
    FX_LOGIC_OP_SET
} fxLogicOp;

typedef enum fxPrimitiveType {
    FX_PRIMITIVE_TYPE_TRIANGLE_LIST,
    FX_PRIMITIVE_TYPE_TRIANGLE_STRIP,
    FX_PRIMITIVE_TYPE_TRIANGLE_FAN,
    FX_PRIMITIVE_TYPE_POINT_LIST,
    FX_PRIMITIVE_TYPE_LINE_LIST,
    FX_PRIMITIVE_TYPE_LINE_STRIP,
    FX_PRIMITIVE_TYPE_PATCH_LIST
} fxPrimitiveType;

typedef enum fxIndexType {
    FX_INDEX_TYPE_U16,
    FX_INDEX_TYPE_U32,
    FX_INDEX_TYPE_COUNT
} fxIndexType;

typedef enum fxBufferType {
    FX_BUFFER_TYPE_VERTEX,
    FX_BUFFER_TYPE_INDEX,
    FX_BUFFER_TYPE_UNIFORM
} fxBufferType;

typedef enum fxSwizzle {
    FX_SWIZZLE_INDENTITY,
    FX_SWIZZLE_ZERO,
    FX_SWIZZLE_ONE,
    FX_SWIZZLE_R,
    FX_SWIZZLE_G,
    FX_SWIZZLE_B,
    FX_SWIZZLE_A
} fxSwizzle;

typedef enum fxFormat {
    FX_FORMAT_INVALID,

    FX_FORMAT_BC1,
    FX_FORMAT_BC2,
    FX_FORMAT_BC3,
    FX_FORMAT_ETC1,
    FX_FORMAT_ETC2,
    FX_FORMAT_ETC2A,
    FX_FORMAT_ETC2A1,

    FX_FORMAT_R8UN,
    FX_FORMAT_R8IN,
    FX_FORMAT_R8U,
    FX_FORMAT_R8I,
    FX_FORMAT_R8G8UN,
    FX_FORMAT_R8G8IN,
    FX_FORMAT_R8G8U,
    FX_FORMAT_R8G8I,
    FX_FORMAT_R8G8B8UN,
    FX_FORMAT_R8G8B8IN,
    FX_FORMAT_R8G8B8U,
    FX_FORMAT_R8G8B8I,
    FX_FORMAT_R8G8B8A8UN,
    FX_FORMAT_R8G8B8A8IN,
    FX_FORMAT_R8G8B8A8U,
    FX_FORMAT_R8G8B8A8I,
    FX_FORMAT_B8G8R8A8UN,
    FX_FORMAT_B8G8R8A8IN,
    FX_FORMAT_B8G8R8A8U,
    FX_FORMAT_B8G8R8A8I,

    FX_FORMAT_R16UN,
    FX_FORMAT_R16IN,
    FX_FORMAT_R16U,
    FX_FORMAT_R16I,
    FX_FORMAT_R16G16UN,
    FX_FORMAT_R16G16IN,
    FX_FORMAT_R16G16U,
    FX_FORMAT_R16G16I,
    FX_FORMAT_R16G16B16UN,
    FX_FORMAT_R16G16B16IN,
    FX_FORMAT_R16G16B16U,
    FX_FORMAT_R16G16B16I,
    FX_FORMAT_R16G16B16A16UN,
    FX_FORMAT_R16G16B16A16IN,
    FX_FORMAT_R16G16B16A16U,
    FX_FORMAT_R16G16B16A16I,
    FX_FORMAT_B16G16R16A16UN,
    FX_FORMAT_B16G16R16A16IN,
    FX_FORMAT_B16G16R16A16U,
    FX_FORMAT_B16G16R16A16I,

    FX_FORMAT_R32UN,
    FX_FORMAT_R32IN,
    FX_FORMAT_R32U,
    FX_FORMAT_R32I,
    FX_FORMAT_R32G32UN,
    FX_FORMAT_R32G32IN,
    FX_FORMAT_R32G32U,
    FX_FORMAT_R32G32I,
    FX_FORMAT_R32G32B32UN,
    FX_FORMAT_R32G32B32IN,
    FX_FORMAT_R32G32B32U,
    FX_FORMAT_R32G32B32I,
    FX_FORMAT_R32G32B32A32UN,
    FX_FORMAT_R32G32B32A32IN,
    FX_FORMAT_R32G32B32A32U,
    FX_FORMAT_R32G32B32A32I,
    FX_FORMAT_B32G32R32A32UN,
    FX_FORMAT_B32G32R32A32IN,
    FX_FORMAT_B32G32R32A32U,
    FX_FORMAT_B32G32R32A32I,

    FX_FORMAT_R16FN,
    FX_FORMAT_R16F,
    FX_FORMAT_R16G16FN,
    FX_FORMAT_R16G16F,
    FX_FORMAT_R16G16B16FN,
    FX_FORMAT_R16G16B16F,
    FX_FORMAT_R16G16B16A16FN,
    FX_FORMAT_R16G16B16A16F,
    FX_FORMAT_B16G16R16A16FN,
    FX_FORMAT_B16G16R16A16F,

    FX_FORMAT_R32FN,
    FX_FORMAT_R32F,
    FX_FORMAT_R32G32FN,
    FX_FORMAT_R32G32F,
    FX_FORMAT_R32G32B32FN,
    FX_FORMAT_R32G32B32F,
    FX_FORMAT_R32G32B32A32FN,
    FX_FORMAT_R32G32B32A32F,
    FX_FORMAT_B32G32R32A32FN,
    FX_FORMAT_B32G32R32A32F,

    FX_FORMAT_D16UN,
    FX_FORMAT_D24S8UN,
    FX_FORMAT_D32F,

    FX_FORMAT_COUNT
} fxFormat;

typedef enum fxFilterMode {
    FX_FILTER_MODE_NEAREST,
    FX_FILTER_MODE_LINEAR
} fxFilterMode;

typedef enum fxFilterMipmapMode {
    FX_FILTER_MIPMAP_MODE_NONE,
    FX_FILTER_MIPMAP_MODE_NEAREST_NEAREST,
    FX_FILTER_MIPMAP_MODE_LINEAR_NEAREST,
    FX_FILTER_MIPMAP_MODE_NEAREST_LINEAR,
    FX_FILTER_MIPMAP_MODE_LINEAR_LINEAR
} fxFilterMipmapMode;

typedef enum fxWrapMode {
    FX_WRAP_MODE_REPEAT,
    FX_WRAP_MODE_MIRRORED_REPEAT,
    FX_WRAP_MODE_CLAMP_TO_EDGE,
    FX_WRAP_MODE_CLAMP_TO_BORDER,
    FX_WRAP_MODE_MIRROR_CLAMP_TO_EDGE
} fxWrapMode;

typedef enum fxStencilOp {
    FX_STENCIL_OP_KEEP,
    FX_STENCIL_OP_ZERO,
    FX_STENCIL_OP_REPLACE,
    FX_STENCIL_OP_INCREMENT_AND_CLAMP,
    FX_STENCIL_OP_DECREMENT_AND_CLAMP,
    FX_STENCIL_OP_INVERT,
    FX_STENCIL_OP_INCREMENT_AND_WRAP,
    FX_STENCIL_OP_DECREMENT_AND_WRAP
} fxStencilOp;

typedef enum fxFillMode {
    FX_FILL_MODE_FILL,
    FX_FILL_MODE_LINE,
    FX_FILL_MODE_POINT
} fxFillMode;

typedef enum fxCullMode {
    FX_CULL_MODE_NONE,
    FX_CULL_MODE_FRONT,
    FX_CULL_MODE_BACK,
    FX_CULL_MODE_FRONT_AND_BACK
} fxCullMode;

typedef enum fxWindingMode {
    FX_WINDING_MODE_CCW,
    FX_WINDING_MODE_CW
} fxWindingMode;

typedef struct fxBufferCfg {
    const char* label;
    fxBufferType type;
    uint32_t size;
    uint32_t flags;
} fxBufferCfg;

typedef enum fxShaderStage {
    FX_SHADER_STAGE_VERTEX,
    FX_SHADER_STAGE_TESSELLATION_CONTROL,
    FX_SHADER_STAGE_TESSELLATION_EVALUATION,
    FX_SHADER_STAGE_GEOMETRY,
    FX_SHADER_STAGE_FRAGMENT,
    FX_SHADER_STAGE_COUNT
} fxShaderStage;

typedef struct fxShaderCfg {
    const char* label;
    fxShaderStage stage;
    const char* entry;
    const char* source;
    uint32_t size;
    uint32_t flags;
} fxShaderCfg;

typedef enum fxTextureType {
    FX_TEXTURE_TYPE_2D,
    FX_TEXTURE_TYPE_ARRAY,
    FX_TEXTURE_TYPE_COUNT
} fxTextureType;

typedef struct fxTextureRegion {
    struct {
        uint32_t x, y, z;
    } src_offset, dst_offset;
    uint32_t width, height, depth;
} fxTextureRegion;

typedef struct fxTextureCfg {
    const char* label;
    fxTextureType type;
    fxFormat format;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    fxSwizzle swizzle_r;
    fxSwizzle swizzle_g;
    fxSwizzle swizzle_b;
    fxSwizzle swizzle_a;

    uint8_t mipmaps;
    uint8_t samples;

    uint32_t flags;
} fxTextureCfg;

typedef struct fxSamplerCfg {
    const char* label;
    fxFilterMode filter_min;
    fxFilterMode filter_mag;
    fxFilterMipmapMode filter_mipmap;
    fxWrapMode wrap_u;
    fxWrapMode wrap_v;
    fxWrapMode wrap_w;
    float lod_mip_bias;
    float anisotropy_max;
    fxCompareOp compare_op;
    float lod_min;
    float lod_max;
    uint32_t flags;
} fxSamplerCfg;

typedef struct fxAttachmentCfg {
    fxTexture texture;
    uint32_t flags;
} fxAttachmentCfg;

typedef struct fxPassCfg {
    const char* label;
    fxAttachmentCfg colours[FX_CONFIG_ATTACHMENT_MAX];
    fxAttachmentCfg depth_stencil;
    uint32_t flags;
} fxPassCfg;

typedef enum fxPassOpType {
    FX_PASS_OP_TYPE_NONE,
    FX_PASS_OP_TYPE_CLEAR,
    FX_PASS_OP_TYPE_COUNT
} fxPassOpType;

typedef struct fxPassOp {
    struct {
        fxPassOpType type;
        uint32_t clear;
    } colours[FX_CONFIG_ATTACHMENT_MAX];
    struct {
        fxPassOpType type;
        float clear;
    } depth;
    struct {
        fxPassOpType type;
        int32_t clear;
    } stencil;
} fxPassOp;

typedef struct fxPipelineBlendCfg {
    fxLogicOp op_logic;
    fxBlendOp op_colour;
    fxBlendOp op_alpha;
    fxBlendFactor factor_src_colour;
    fxBlendFactor factor_src_alpha;
    fxBlendFactor factor_dst_colour;
    fxBlendFactor factor_dst_alpha;
    uint32_t colour_mask;
    float colour[4];
    uint32_t flags;
} fxPipelineBlendCfg;

typedef struct fxStencilOpCfg {
    fxStencilOp op_fail;
    fxStencilOp op_pass;
    fxStencilOp op_depth_fail;
    fxCompareOp op_cmp;
    uint32_t mask_cmp;
    uint32_t mask_write;
    uint32_t ref;
} fxStencilOpCfg;

typedef struct fxPipelineDepthStencilCfg {
    fxCompareOp depth_op;
    float depth_min;
    float depth_max;
    fxStencilOpCfg front;
    fxStencilOpCfg back;
    uint32_t flags;
} fxPipelineDepthStencilCfg;

typedef struct fxPipelineRasterCfg {
    fxFillMode fill;
    fxCullMode cull;
    fxWindingMode winding;
    float line_width;
    float point_size;
    uint8_t samples;
    uint32_t flags;
} fxPipelineRasterCfg;

typedef enum fxVertexRate {
    FX_VERTEX_RATE_PER_VERTEX,
    FX_VERTEX_RATE_PER_INSTANCE,
    FX_VERTEX_RATE_PER_COUNT
} fxVertexRate;

typedef enum fxAttribSemantic {
    FX_ATTRIB_SEMANTIC_POSITION,
    FX_ATTRIB_SEMANTIC_NORMAL,
    FX_ATTRIB_SEMANTIC_TANGENT,
    FX_ATTRIB_SEMANTIC_BITANGENT,
    FX_ATTRIB_SEMANTIC_COLOUR0,
    FX_ATTRIB_SEMANTIC_COLOUR1,
    FX_ATTRIB_SEMANTIC_COLOUR2,
    FX_ATTRIB_SEMANTIC_COLOUR3,
    FX_ATTRIB_SEMANTIC_INDICES,
    FX_ATTRIB_SEMANTIC_WEIGHTS,
    FX_ATTRIB_SEMANTIC_TEXCOORD0,
    FX_ATTRIB_SEMANTIC_TEXCOORD1,
    FX_ATTRIB_SEMANTIC_TEXCOORD2,
    FX_ATTRIB_SEMANTIC_TEXCOORD3,
    FX_ATTRIB_SEMANTIC_TEXCOORD4,
    FX_ATTRIB_SEMANTIC_TEXCOORD5,
    FX_ATTRIB_SEMANTIC_TEXCOORD6,
    FX_ATTRIB_SEMANTIC_TEXCOORD7,
    FX_ATTRIB_SEMANTIC_COUNT
} fxAttribSemantic;

typedef struct fxVertexAttrib {
    uint8_t binding;
    uint8_t location;
    char name[32];
    fxFormat format;
    fxAttribSemantic semantic;
    uint32_t offset;
} fxVertexAttrib;

typedef struct fxPipelineLayoutCfg {
    fxVertexAttrib attribs[FX_ATTRIB_SEMANTIC_COUNT];
    fxVertexRate rate;
    uint32_t stride;
    uint32_t flags;
} fxPipelineLayoutCfg;

typedef struct fxPipelineShaderCfg {
    fxShader vertex;
    fxShader tessellation_control;
    fxShader tessellation_evaluation;
    fxShader geometry;
    fxShader fragment;
    uint32_t flags;
} fxPipelineShaderCfg;

typedef struct fxPipelineCfg {
    fxPipelineShaderCfg shader;
    fxPipelineBlendCfg blend;
    fxPipelineRasterCfg raster;
    fxPipelineDepthStencilCfg depth_stencil;
    fxPipelineLayoutCfg layouts[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    uint32_t flags;
} fxPipelineCfg;

typedef struct fxCfg {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);
    void* usr_fn_address;
    fxFn (*fn_address)(void* usr, const char* name);
} fxCfg;

FX_API fxCtx fx(fxCfg* cfg);
FX_API void fx_destroy(fxCtx ctx);
FX_API void fx_submit(fxCtx ctx, fxCmdBuffer* cmd_buffers, uint32_t count);
FX_API void fx_flush(fxCtx ctx);

FX_API fxPipeline fx_pipeline(fxCtx ctx, fxPipelineCfg* cfg);
FX_API void fx_pipeline_destroy(fxCtx ctx, fxPipeline pipeline);

FX_API fxPass fx_pass(fxCtx ctx, fxPassCfg* cfg);
FX_API void fx_pass_destroy(fxCtx ctx, fxPass pass);

FX_API fxBuffer fx_buffer(fxCtx ctx, fxBufferCfg* cfg, void* data, uint32_t size);
FX_API void fx_buffer_destroy(fxCtx ctx, fxBuffer buffer);
FX_API void fx_buffer_update(fxCtx ctx, fxBuffer buffer, void* data, uint32_t size, uint32_t offset);

FX_API fxTexture fx_texture(fxCtx ctx, fxTextureCfg* cfg, void* data, uint32_t size);
FX_API void fx_texture_destroy(fxCtx ctx, fxTexture texture);
FX_API void fx_texture_update(fxCtx ctx, fxTexture texture, void* data, fxTextureRegion* region);

FX_API fxSampler fx_sampler(fxCtx ctx, fxSamplerCfg* cfg);
FX_API void fx_sampler_destroy(fxCtx ctx, fxSampler sampler);

FX_API fxShader fx_shader(fxCtx ctx, fxShaderCfg* cfg);
FX_API void fx_shader_destroy(fxCtx ctx, fxShader shader);

FX_API fxCmdBuffer fx_cmd_buffer(fxCtx ctx);
FX_API void fx_cmd_buffer_destroy(fxCtx ctx, fxCmdBuffer cmd_buffer);
FX_API void fx_cmd_buffer_reset(fxCmdBuffer cmd_buffer);

FX_API void fx_cmd_begin_default_pass(fxCmdBuffer cmd_buffer, uint32_t colour, float depth, int32_t stencil);
FX_API void fx_cmd_begin_pass(fxCmdBuffer cmd_buffer, fxPass pass, fxPassOp* ops);
FX_API void fx_cmd_end_pass(fxCmdBuffer cmd_buffer);

FX_API void fx_cmd_viewport(fxCmdBuffer cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
FX_API void fx_cmd_scissor(fxCmdBuffer cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

FX_API void fx_cmd_bind_pipeline(fxCmdBuffer cmd_buffer, fxPipeline pipeline);
FX_API void fx_cmd_bind_vertex_buffers(fxCmdBuffer cmd_buffer, fxBuffer* buffers, uint8_t count);
FX_API void fx_cmd_bind_index_buffer(fxCmdBuffer cmd_buffer, fxBuffer index_buffer, fxIndexType type);
FX_API void fx_cmd_bind_uniform_buffer(fxCmdBuffer cmd_buffer, fxBuffer uniform_buffer, uint8_t index, uint32_t size, uint32_t offset);
FX_API void fx_cmd_bind_textures(fxCmdBuffer cmd_buffer, fxTexture* textures, uint8_t count);
FX_API void fx_cmd_bind_samplers(fxCmdBuffer cmd_buffer, fxSampler* samplers, uint8_t count);
FX_API void fx_cmd_bind_texture_units(fxCmdBuffer cmd_buffer, fxTexture* textures, uint8_t* units, uint8_t count);
FX_API void fx_cmd_bind_sampler_units(fxCmdBuffer cmd_buffer, fxSampler* samplers, uint8_t* units, uint8_t count);

FX_API void fx_cmd_buffer_update(fxCmdBuffer cmd_buffer, fxBuffer buffer, void* data, uint32_t size, uint32_t offset);
FX_API void fx_cmd_buffer_copy(fxCmdBuffer cmd_buffer, fxBuffer src, fxBuffer dst, uint32_t src_offset, uint32_t dst_offset, uint32_t size);

FX_API void fx_cmd_texture_copy(fxCmdBuffer cmd_buffer, fxTexture src, fxTexture dst, fxTextureRegion* region);

FX_API void fx_cmd_draw(fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_vertex);
FX_API void fx_cmd_draw_indexed(fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex);
FX_API void fx_cmd_draw_instanced(fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_vertex, uint32_t instance_count);
FX_API void fx_cmd_draw_instanced_indexed(fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex, uint32_t instance_count);

#if defined(__cplusplus)
}
#endif

#endif

#if defined(FX_IMPL)

#if !defined(FX_ASSERT)
#include <assert.h>
#define FX_ASSERT(c) assert(c)
#endif

#if !defined(FX_MALLOC)
#include <stdlib.h>
#define FX_MALLOC(s) malloc(s)
#define FX_FREE(p) free(p)
#endif

#if !defined(FX_MEMSET)
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#define FX_MEMSET(s, c, sz) __builtin_memset((s), (c), (sz))
#else
#include <string.h>
#define FX_MEMSET(s, c, sz) memset((s), (c), (sz))
#endif
#endif

#if !defined(FX_MEMCOPY)
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#define FX_MEMCOPY(d, s, sz) __builtin_memcpy((d), (s), (sz))
#else
#include <string.h>
#define FX_MEMCOPY(d, s, sz) memcpy((d), (s), (sz))
#endif
#endif

#if !defined(FX_COUNT_OF)
#define FX_COUNT_OF(a) (sizeof(a) / sizeof((a)[0]))
#endif

#if !defined(FX_MAX)
#define FX_MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

static const char* _FX_SHADER_STAGE_NAME[] = {
    "Vertex",
    "Hull",
    "Domain",
    "Geometry",
    "Fragment",
};

typedef struct fxPoolAllocator {
    void* data;
    uint64_t size;
    uint64_t used;

    uint64_t item_size;
    void* freelist;
} fxPoolAllocator;

fxPoolAllocator fx_pool_allocator(void* data, uint64_t item_count, uint64_t item_size) {
    fxPoolAllocator res;
    res.data = data;

    void* curr = data;
    for(uint64_t i = 0; i < (item_count - 1); i++) {
        uint64_t* next = (uint64_t*) curr;
        *next = ((uint64_t) curr) + item_size;
        curr = (void*) (((uint8_t*) curr) + item_size);
    }

    uint64_t* end = (uint64_t*) curr;
    *end = (uint64_t) NULL;

    res.size = item_count * item_size;
    res.used = 0;
    res.item_size = item_size;
    res.freelist = res.data;
    return res;
}

void* fx_pool_alloc(fxPoolAllocator* allocator) {
    void* res = NULL;
    if(allocator->freelist) {
        uint64_t next = *((uint64_t*) allocator->freelist);
        res = allocator->freelist;
        allocator->freelist = (void**) next;
        allocator->used += allocator->item_size;
    }
    return res;
}

void fx_pool_free(fxPoolAllocator* allocator, void* ptr) {
    *((void**) ptr) = allocator->freelist;
    allocator->freelist = ((void**) ptr);
    allocator->used -= allocator->item_size;
}

typedef struct fxBackendBuffer fxBackendBuffer;
typedef struct fxBackendCtx fxBackendCtx;
typedef struct fxBackendPass fxBackendPass;
typedef struct fxBackendPipeline fxBackendPipeline;
typedef struct fxBackendRenderTarget fxBackendRenderTarget;
typedef struct fxBackendSampler fxBackendSampler;
typedef struct fxBackendShader fxBackendShader;
typedef struct fxBackendTexture fxBackendTexture;

typedef struct fxBackendApi {
    void (*destroy)(fxBackendCtx* ctx);

    fxBackendPipeline* (*pipeline)(fxBackendCtx* ctx, fxPipelineCfg* cfg);
    void (*pipeline_destroy)(fxBackendCtx* ctx, fxBackendPipeline* pipeline);

    fxBackendBuffer* (*buffer)(fxBackendCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size);
    void (*buffer_destroy)(fxBackendCtx* ctx, fxBackendBuffer* buffer);
    void (*buffer_update)(fxBackendCtx* ctx, fxBackendBuffer* buffer, void* data, uint32_t size, uint32_t offset);

    fxBackendShader* (*shader)(fxBackendCtx* ctx, fxShaderCfg* cfg);
    void (*shader_destroy)(fxBackendCtx* ctx, fxBackendShader* shader);

    fxBackendTexture* (*texture)(fxBackendCtx* ctx, fxTextureCfg* cfg, void* data, uint32_t size);
    void (*texture_destroy)(fxBackendCtx* ctx, fxBackendTexture* texture);
    void (*texture_update)(fxBackendCtx* ctx, fxBackendTexture* texture, void* data, fxTextureRegion* region);

    fxBackendSampler* (*sampler)(fxBackendCtx* ctx, fxSamplerCfg* cfg);
    void (*sampler_destroy)(fxBackendCtx* ctx, fxBackendSampler* sampler);

    fxBackendPass* (*pass)(fxBackendCtx* ctx, fxPassCfg* cfg);
    void (*pass_destroy)(fxBackendCtx* ctx, fxBackendPass* pass);

    void (*submit)(fxBackendCtx* ctx, fxCmdBuffer cmd_buffer);
} fxBackendApi;

fxBackendCtx* fx_backend(fxCfg* cfg, fxBackendApi* api);

typedef enum fxCmdBufferState {
    FX_CMD_BUFFER_STATE_INACTIVE,
    FX_CMD_BUFFER_STATE_ACTIVE,
    FX_CMD_BUFFER_STATE_PENDING,
    FX_CMD_BUFFER_STATE_COUNT
} fxCmdBufferState;

// SoA -> AoS?
struct fxCmdBufferT {
    fxCmdBufferState state;
    uint32_t used;
    uint8_t cmds[FX_CONFIG_CMD_BUFFER_CMD_MAX];
};

struct fxCtxT {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    struct fxCmdBufferT cmd_buffers[FX_CONFIG_CMD_BUFFER_MAX];
    fxPoolAllocator cmd_buffer_allocator;

    fxBackendCtx* backend;
    fxBackendApi api;
};

static void _fx_dummy_log(void* usr, const char* fmt, ...) {
    (void) usr;
    (void) fmt;
}

fxCtx fx(fxCfg* cfg) {
    struct fxCtxT* res = (struct fxCtxT*) FX_MALLOC(sizeof(struct fxCtxT));
    FX_MEMSET(res, 0, sizeof(struct fxCtxT));
    res->usr = cfg->usr;
    res->log = cfg->log ? cfg->log: _fx_dummy_log;
    res->cmd_buffer_allocator = fx_pool_allocator(res->cmd_buffers, FX_CONFIG_CMD_BUFFER_MAX, sizeof(struct fxCmdBufferT));
    res->backend = fx_backend(cfg, &res->api);
    return res;
}

void fx_destroy(fxCtx ctx) {
    ctx->api.destroy(ctx->backend);
    FX_MEMSET(ctx, 0, sizeof(struct fxCtxT));
}

void fx_submit(fxCtx ctx, fxCmdBuffer* cmd_buffers, uint32_t count) {
    for(uint32_t i = 0; i < count; i++) {
        FX_ASSERT(cmd_buffers[i]->state == FX_CMD_BUFFER_STATE_INACTIVE);
        cmd_buffers[i]->state = FX_CMD_BUFFER_STATE_PENDING;
        ctx->api.submit(ctx->backend, cmd_buffers[i]);
        cmd_buffers[i]->state = FX_CMD_BUFFER_STATE_INACTIVE;
    }
}

fxPipeline fx_pipeline(fxCtx ctx, fxPipelineCfg* cfg) {
    return (fxPipeline) ctx->api.pipeline(ctx->backend, cfg);
}

void fx_pipeline_destroy(fxCtx ctx, fxPipeline pipeline) {
    ctx->api.pipeline_destroy(ctx->backend, pipeline);
}

fxPass fx_pass(fxCtx ctx, fxPassCfg* cfg) {
    return (fxPass) ctx->api.pass(ctx->backend, cfg);
}

void fx_pass_destroy(fxCtx ctx, fxPass pass) {
    ctx->api.pass_destroy(ctx->backend, pass);
}

fxBuffer fx_buffer(fxCtx ctx, fxBufferCfg* cfg, void* data, uint32_t size) {
    return (fxBuffer) ctx->api.buffer(ctx->backend, cfg, data, size);
}

void fx_buffer_destroy(fxCtx ctx, fxBuffer buffer) {
    ctx->api.buffer_destroy(ctx->backend, buffer);
}

void fx_buffer_update(fxCtx ctx, fxBuffer buffer, void* data, uint32_t size, uint32_t offset) {
    ctx->api.buffer_update(ctx->backend, buffer, data, size, offset);
}

fxTexture fx_texture(fxCtx ctx, fxTextureCfg* cfg, void* data, uint32_t size) {
    return (fxTexture) ctx->api.texture(ctx->backend, cfg, data, size);
}

void fx_texture_destroy(fxCtx ctx, fxTexture texture) {
    ctx->api.texture_destroy(ctx->backend, texture);
}

void fx_texture_update(fxCtx ctx, fxTexture texture, void* data, fxTextureRegion* region) {
    ctx->api.texture_update(ctx->backend, texture, data, region);
}

fxSampler fx_sampler(fxCtx ctx, fxSamplerCfg* cfg) {
    return (fxSampler) ctx->api.sampler(ctx->backend, cfg);
}

void fx_sampler_destroy(fxCtx ctx, fxSampler sampler) {
    ctx->api.sampler_destroy(ctx->backend, sampler);
}

fxShader fx_shader(fxCtx ctx, fxShaderCfg* cfg) {
    return (fxShader) ctx->api.shader(ctx->backend, cfg);
}

void fx_shader_destroy(fxCtx ctx, fxShader shader) {
    ctx->api.shader_destroy(ctx->backend, shader);
}

typedef uint8_t fxCmdType;

enum {
    FX_CMD_TYPE_BEGIN_PASS,
    FX_CMD_TYPE_END_PASS,
    FX_CMD_TYPE_BARRIER,
    FX_CMD_TYPE_VIEWPORT,
    FX_CMD_TYPE_SCISSOR,
    FX_CMD_TYPE_BIND_PIPELINE,
    FX_CMD_TYPE_BIND_RENDER_TARGET,
    FX_CMD_TYPE_BIND_VERTEX_BUFFERS,
    FX_CMD_TYPE_BIND_INDEX_BUFFER,
    FX_CMD_TYPE_BIND_UNIFORM_BUFFER,
    FX_CMD_TYPE_BUFFER_UPDATE,
    FX_CMD_TYPE_BUFFER_COPY,
    FX_CMD_TYPE_BIND_TEXTURES,
    FX_CMD_TYPE_BIND_SAMPLERS,
    FX_CMD_TYPE_TEXTURE_COPY,
    FX_CMD_TYPE_TEXTURE_BLIT,
    FX_CMD_TYPE_TEXTURE_UPDATE,
    FX_CMD_TYPE_UPDATE_UNIFORMS,
    FX_CMD_TYPE_DRAW,
    FX_CMD_TYPE_DRAW_INDEXED,
    FX_CMD_TYPE_DRAW_INSTANCED,
    FX_CMD_TYPE_DRAW_INSTANCED_INDEXED,
    FX_CMD_TYPE_COUNT
};

typedef struct fxCmdHeader {
    fxCmdType type;
    uint16_t size;
} fxCmdHeader;

typedef struct fxCmdBeginPass {
    fxBackendPass* pass;
    fxPassOp ops;
} fxCmdBeginPass;

typedef struct fxCmdEndPass {
    fxBackendPass* pass;
} fxCmdEndPass;

typedef struct fxCmdBarrier {
    uint32_t flags;
} fxCmdBarrier;

typedef struct fxCmdViewport {
    uint16_t x, y, width, height;
} fxCmdViewport;

typedef struct fxCmdScissor {
    uint16_t x, y, width, height;
} fxCmdScissor;

typedef struct fxCmdBindPipeline {
    fxBackendPipeline* pipeline;
} fxCmdBindPipeline;

typedef struct fxCmdBindRenderTarget {
    fxBackendRenderTarget* render_target;
} fxCmdBindRenderTarget;

typedef struct fxCmdBindVertexBuffers {
    fxBackendBuffer* vertex_buffers[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    uint8_t count;
} fxCmdBindVertexBuffers;

typedef struct fxCmdBindIndexBuffer {
    fxBackendBuffer* index_buffer;
    fxIndexType index_type;
} fxCmdBindIndexBuffer;

typedef struct fxCmdBindUniformBuffer {
    fxBackendBuffer* uniform_buffer;
    uint8_t index;
    uint32_t size;
    uint32_t offset;
} fxCmdBindUniformBuffer;

typedef struct fxCmdBindTextures {
    fxBackendTexture* textures[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t units[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t count;
} fxCmdBindTextures;

typedef struct fxCmdBindSamplers {
    fxBackendSampler* samplers[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t units[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t count;
} fxCmdBindSamplers;

typedef struct fxCmdUpdateUniforms {
    fxShaderStage stage;
    uint16_t size;
} fxCmdUpdateUniforms;

typedef struct fxCmdBufferUpdate {
    fxBackendBuffer* buffer;
    uint32_t size;
    uint32_t offset;
} fxCmdBufferUpdate;

typedef struct fxCmdBufferCopy {
    fxBackendBuffer* src;
    fxBackendBuffer* dst;
    uint32_t src_offset;
    uint32_t dst_offset;
    uint32_t size;
} fxCmdBufferCopy;

typedef struct fxCmdTextureCopy {
    fxBackendTexture* src;
    fxBackendTexture* dst;
    fxTextureRegion region;
} fxCmdTextureCopy;

typedef struct fxCmdTextureBlit {
    fxBackendTexture* src;
    fxBackendTexture* dst;
    fxTextureRegion region;
} fxCmdTextureBlit;

typedef struct fxCmdTextureUpdate {
    fxBackendTexture* texture;
    fxTextureRegion region;
} fxCmdTextureUpdate;

typedef struct fxCmdDraw {
    fxPrimitiveType primitive;
    uint32_t count;
    uint32_t first_index;
    uint32_t first_vertex;
} fxCmdDraw;

typedef struct fxCmdDrawInstanced {
    fxPrimitiveType primitive;
    uint32_t count;
    uint32_t first_index;
    uint32_t first_vertex;
    uint32_t instance_count;
} fxCmdDrawInstanced;

fxCmdBuffer fx_cmd_buffer(fxCtx ctx) {
    fxCmdBuffer res = (fxCmdBuffer) fx_pool_alloc(&ctx->cmd_buffer_allocator);
    res->state = FX_CMD_BUFFER_STATE_INACTIVE;
    res->used = 0;
    return res;
}

void fx_cmd_buffer_destroy(fxCtx ctx, fxCmdBuffer cmd_buffer) {
    fx_pool_free(&ctx->cmd_buffer_allocator, cmd_buffer);
}

void fx_cmd_buffer_reset(fxCmdBuffer cmd_buffer) {
    FX_ASSERT(cmd_buffer->state != FX_CMD_BUFFER_STATE_PENDING);
    cmd_buffer->state = FX_CMD_BUFFER_STATE_INACTIVE;
    cmd_buffer->used = 0;
}

static uint8_t* _fx_cmd(fxCmdBuffer cmd_buffer, fxCmdType type, uint16_t size) {
    FX_ASSERT(cmd_buffer->state == FX_CMD_BUFFER_STATE_ACTIVE);
    FX_ASSERT((cmd_buffer->used + sizeof(fxCmdHeader) + size) < FX_CONFIG_CMD_BUFFER_CMD_MAX);

    fxCmdHeader* res = (fxCmdHeader*) (cmd_buffer->cmds + cmd_buffer->used);
    FX_MEMSET(res, 0, sizeof(fxCmdHeader) + size);
    res->type = type;
    res->size = size;
    cmd_buffer->used += sizeof(fxCmdHeader) + size;
    return (uint8_t*) (res + 1);
}

void fx_cmd_begin_default_pass(fxCmdBuffer cmd_buffer, uint32_t colour, float depth, int32_t stencil) {
    fxPassOp ops;
    ops.colours[0].type = FX_PASS_OP_TYPE_CLEAR;
    ops.colours[0].clear = colour;
    ops.depth.type = FX_PASS_OP_TYPE_CLEAR;
    ops.depth.clear = depth;
    ops.stencil.type = FX_PASS_OP_TYPE_CLEAR;
    ops.stencil.clear = stencil;
    fx_cmd_begin_pass(cmd_buffer, NULL, &ops);
}

void fx_cmd_begin_pass(fxCmdBuffer cmd_buffer, fxPass pass, fxPassOp* ops) {
    FX_ASSERT(cmd_buffer->state == FX_CMD_BUFFER_STATE_INACTIVE);
    cmd_buffer->state = FX_CMD_BUFFER_STATE_ACTIVE;
    fxCmdBeginPass* cmd = (fxCmdBeginPass*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BEGIN_PASS, sizeof(fxCmdBeginPass));
    cmd->pass = pass;
    FX_MEMCOPY(&cmd->ops, ops, sizeof(fxPassOp));
}

void fx_cmd_end_pass(fxCmdBuffer cmd_buffer) {
    fxCmdEndPass* cmd = (fxCmdEndPass*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_END_PASS, sizeof(fxCmdEndPass));
    (void) cmd;
    cmd_buffer->state = FX_CMD_BUFFER_STATE_INACTIVE;
}

void fx_cmd_barrier(fxCmdBuffer cmd_buffer, uint32_t flags) {
    fxCmdBarrier* cmd = (fxCmdBarrier*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BARRIER, sizeof(fxCmdBarrier));
    cmd->flags = flags;
}

void fx_cmd_viewport(fxCmdBuffer cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    fxCmdViewport* cmd = (fxCmdViewport*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_VIEWPORT, sizeof(fxCmdViewport));
    cmd->x = x;
    cmd->y = y;
    cmd->width = width;
    cmd->height = height;
}

void fx_cmd_scissor(fxCmdBuffer cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    fxCmdScissor* cmd = (fxCmdScissor*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_SCISSOR, sizeof(fxCmdScissor));
    cmd->x = x;
    cmd->y = y;
    cmd->width = width;
    cmd->height = height;
}

void fx_cmd_bind_pipeline(fxCmdBuffer cmd_buffer, fxPipeline pipeline) {
    fxCmdBindPipeline* cmd =
        (fxCmdBindPipeline*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_PIPELINE, sizeof(fxCmdBindPipeline));
    cmd->pipeline = pipeline;
}

void fx_cmd_bind_render_target(fxCmdBuffer cmd_buffer, fxRenderTarget render_target) {
    fxCmdBindRenderTarget* cmd =
        (fxCmdBindRenderTarget*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_RENDER_TARGET, sizeof(fxCmdBindRenderTarget));
    cmd->render_target = render_target;
}

void fx_cmd_bind_vertex_buffers(fxCmdBuffer cmd_buffer, fxBuffer* buffers, uint8_t count) {
    FX_ASSERT(count <= FX_CONFIG_VERTEX_BUFFER_BINDING_MAX);
    fxCmdBindVertexBuffers* cmd =
        (fxCmdBindVertexBuffers*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_VERTEX_BUFFERS, sizeof(fxCmdBindVertexBuffers));
    FX_MEMCOPY(cmd->vertex_buffers, buffers, count * sizeof(fxBuffer));
    cmd->count = count;
}

void fx_cmd_bind_index_buffer(fxCmdBuffer cmd_buffer, fxBuffer index_buffer, fxIndexType type) {
    fxCmdBindIndexBuffer* cmd =
        (fxCmdBindIndexBuffer*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_INDEX_BUFFER, sizeof(fxCmdBindIndexBuffer));
    cmd->index_buffer = index_buffer;
    cmd->index_type = type;
}

void fx_cmd_bind_uniform_buffer(
    fxCmdBuffer cmd_buffer, fxBuffer uniform_buffer, uint8_t index, uint32_t size, uint32_t offset) {
    fxCmdBindUniformBuffer* cmd =
        (fxCmdBindUniformBuffer*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_UNIFORM_BUFFER, sizeof(fxCmdBindUniformBuffer));
    cmd->uniform_buffer = uniform_buffer;
    cmd->index = index;
    cmd->size = size;
    cmd->offset = offset;
}

void fx_cmd_buffer_update(fxCmdBuffer cmd_buffer, fxBuffer buffer, void* data, uint32_t size, uint32_t offset) {
    fxCmdBufferUpdate* cmd =
        (fxCmdBufferUpdate*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BUFFER_UPDATE, sizeof(fxCmdBufferUpdate) + size);
    FX_MEMCOPY(cmd + 1, data, size);
    cmd->buffer = buffer;
    cmd->size = size;
    cmd->offset = offset;
}

void fx_cmd_buffer_copy(
    fxCmdBuffer cmd_buffer, fxBuffer src, fxBuffer dst, uint32_t src_offset, uint32_t dst_offset, uint32_t size) {
    fxCmdBufferCopy* cmd = (fxCmdBufferCopy*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BUFFER_COPY, sizeof(fxCmdBufferCopy));
    cmd->src = src;
    cmd->dst = dst;
    cmd->src_offset = src_offset;
    cmd->dst_offset = dst_offset;
    cmd->size = size;
}

void fx_cmd_bind_textures(fxCmdBuffer cmd_buffer, fxTexture* textures, uint8_t count) {
    fx_cmd_bind_texture_units(cmd_buffer, textures, NULL, count);
}

void fx_cmd_bind_samplers(fxCmdBuffer cmd_buffer, fxSampler* samplers, uint8_t count) {
    fx_cmd_bind_sampler_units(cmd_buffer, samplers, NULL, count);
}

void fx_cmd_bind_texture_units(fxCmdBuffer cmd_buffer, fxTexture* textures, uint8_t* units, uint8_t count) {
    fxCmdBindTextures* cmd =
        (fxCmdBindTextures*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_TEXTURES, sizeof(fxCmdBindTextures));
    FX_MEMCOPY(cmd->textures, textures, count * sizeof(fxTexture));
    if(units) {
        FX_MEMCOPY(cmd->units, units, count * sizeof(uint8_t));
    } else {
        FX_MEMSET(cmd->units, (uint8_t) -1, count);
    }
    cmd->count = count;
}

void fx_cmd_bind_sampler_units(fxCmdBuffer cmd_buffer, fxSampler* samplers, uint8_t* units, uint8_t count) {
    fxCmdBindSamplers* cmd =
        (fxCmdBindSamplers*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_BIND_SAMPLERS, sizeof(fxCmdBindSamplers));
    FX_MEMCOPY(cmd->samplers, samplers, count * sizeof(fxSampler));
    if(units) {
        FX_MEMCOPY(cmd->units, units, count * sizeof(uint8_t));
    } else {
        FX_MEMSET(cmd->units, (uint8_t) -1, count);
    }
    cmd->count = count;
}

void fx_cmd_texture_copy(fxCmdBuffer cmd_buffer, fxTexture src, fxTexture dst, fxTextureRegion* region) {
    fxCmdTextureCopy* cmd = (fxCmdTextureCopy*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_TEXTURE_COPY, sizeof(fxCmdTextureCopy));
    cmd->src = src;
    cmd->dst = dst;
    cmd->region = *region;
}

void fx_cmd_texture_blit(fxCmdBuffer cmd_buffer, fxTexture src, fxTexture dst, fxTextureRegion* region) {
    fxCmdTextureBlit* cmd = (fxCmdTextureBlit*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_TEXTURE_BLIT, sizeof(fxCmdTextureBlit));
    cmd->src = src;
    cmd->dst = dst;
    cmd->region = *region;
}

void fx_cmd_texture_update(fxCmdBuffer cmd_buffer, fxTexture texture, void* data, fxTextureRegion* region) {
    FX_ASSERT(!"Unimplemented");
    (void) data;
    fxCmdTextureUpdate* cmd =
        (fxCmdTextureUpdate*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_TEXTURE_UPDATE, sizeof(fxCmdTextureUpdate));
    cmd->texture = texture;
    cmd->region = *region;
}

void fx_cmd_draw(fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_vertex) {
    fxCmdDraw* cmd = (fxCmdDraw*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_DRAW, sizeof(fxCmdDraw));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_vertex = first_vertex;
}

void fx_cmd_draw_indexed(
    fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex) {
    fxCmdDraw* cmd = (fxCmdDraw*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_DRAW_INDEXED, sizeof(fxCmdDraw));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_index = first_index;
    cmd->first_vertex = first_vertex;
}

void fx_cmd_draw_instanced(
    fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_vertex, uint32_t instance_count) {
    fxCmdDrawInstanced* cmd =
        (fxCmdDrawInstanced*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_DRAW_INSTANCED, sizeof(fxCmdDrawInstanced));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_vertex = first_vertex;
    cmd->instance_count = instance_count;
}

void fx_cmd_draw_instanced_indexed(
    fxCmdBuffer cmd_buffer, fxPrimitiveType primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex,
    uint32_t instance_count) {
    fxCmdDrawInstanced* cmd =
        (fxCmdDrawInstanced*) _fx_cmd(cmd_buffer, FX_CMD_TYPE_DRAW_INSTANCED_INDEXED, sizeof(fxCmdDrawInstanced));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_index = first_index;
    cmd->first_vertex = first_vertex;
    cmd->instance_count = instance_count;
}

#if defined(FX_GL45_IMPL)
#include "fx.gl45.h"
#elif defined(FX_DX11_IMPL)
#include "fx.dx11.h"
#else
#error "No implementation"
#endif

#endif
