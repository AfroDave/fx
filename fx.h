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
#define FX_VERSION_MINOR 16
#define FX_VERSION_PATCH 3

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
#define FX_CONFIG_CMD_BUFFER_CMD_MAX (4096 * 8)
#define FX_CONFIG_TEXTURE_MAX (128)
#define FX_CONFIG_BUFFER_MAX (128)
#define FX_CONFIG_VERTEX_BUFFER_BINDING_MAX (8)
#define FX_CONFIG_UNIFORM_BUFFER_BINDING_MAX (4)
#define FX_CONFIG_TEXTURE_BINDING_MAX (4)
#define FX_CONFIG_SHADER_MAX (64)
#define FX_CONFIG_PIPELINE_MAX (32)
#define FX_CONFIG_PASS_MAX (16)
#define FX_CONFIG_ATTACHMENT_MAX (8)

typedef uint32_t fxId;

#define FX_ID_INVALID ((fxId) 0)

typedef struct fxCtx fxCtx;
typedef struct fxCmdBuffer fxCmdBuffer;
typedef fxId fxPassId;
typedef fxId fxShaderId;
typedef fxId fxPipelineId;
typedef fxId fxBufferId;
typedef fxId fxTextureId;
typedef fxId fxSamplerId;

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
    FX_PIPELINE_RASTER_ALPHA_TO_COVERAGE = 1 << 2,
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

typedef enum fxPrimitiveKind {
    FX_PRIMITIVE_KIND_TRIANGLE_LIST,
    FX_PRIMITIVE_KIND_TRIANGLE_STRIP,
    FX_PRIMITIVE_KIND_TRIANGLE_FAN,
    FX_PRIMITIVE_KIND_POINT_LIST,
    FX_PRIMITIVE_KIND_LINE_LIST,
    FX_PRIMITIVE_KIND_LINE_STRIP,
    FX_PRIMITIVE_KIND_PATCH_LIST
} fxPrimitiveKind;

typedef enum fxIndexKind {
    FX_INDEX_KIND_U16,
    FX_INDEX_KIND_U32,
    FX_INDEX_KIND_COUNT
} fxIndexKind;

typedef enum fxBufferKind {
    FX_BUFFER_KIND_VERTEX,
    FX_BUFFER_KIND_INDEX,
    FX_BUFFER_KIND_UNIFORM
} fxBufferKind;

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

    FX_FORMAT_R16FN,
    FX_FORMAT_R16F,
    FX_FORMAT_R16G16FN,
    FX_FORMAT_R16G16F,
    FX_FORMAT_R16G16B16FN,
    FX_FORMAT_R16G16B16F,
    FX_FORMAT_R16G16B16A16FN,
    FX_FORMAT_R16G16B16A16F,

    FX_FORMAT_R32FN,
    FX_FORMAT_R32F,
    FX_FORMAT_R32G32FN,
    FX_FORMAT_R32G32F,
    FX_FORMAT_R32G32B32FN,
    FX_FORMAT_R32G32B32F,
    FX_FORMAT_R32G32B32A32FN,
    FX_FORMAT_R32G32B32A32F,

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
    fxBufferKind kind;
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

typedef enum fxTextureKind {
    FX_TEXTURE_KIND_2D,
    FX_TEXTURE_KIND_ARRAY,
    FX_TEXTURE_KIND_COUNT
} fxTextureKind;

typedef struct fxTextureRegion {
    struct {
        uint32_t x, y, z;
    } src_offset, dst_offset;
    int32_t width, height, depth;
} fxTextureRegion;

typedef struct fxTextureCfg {
    const char* label;
    fxTextureKind kind;
    fxFormat format;
    int32_t width;
    int32_t height;
    int32_t depth;
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
    fxTextureId texture;
    uint32_t flags;
} fxAttachmentCfg;

typedef struct fxPassCfg {
    const char* label;
    fxAttachmentCfg colours[FX_CONFIG_ATTACHMENT_MAX];
    fxAttachmentCfg depth_stencil;
    uint32_t flags;
} fxPassCfg;

typedef enum fxPassOpKind {
    FX_PASS_OP_KIND_NONE,
    FX_PASS_OP_KIND_CLEAR,
    FX_PASS_OP_KIND_COUNT
} fxPassOpKind;

typedef struct fxPassOp {
    struct {
        fxPassOpKind kind;
        uint32_t clear;
    } colours[FX_CONFIG_ATTACHMENT_MAX];
    struct {
        fxPassOpKind kind;
        float clear;
    } depth;
    struct {
        fxPassOpKind kind;
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
    fxShaderId vertex;
    fxShaderId tessellation_control;
    fxShaderId tessellation_evaluation;
    fxShaderId geometry;
    fxShaderId fragment;
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

typedef struct fxSystemInfo {
    const char* api;
    const char* version;
    const char* device;
    const char* vendor;
    const char* shading_language;
    bool texture_copy_support;
    bool geometry_shader_support;
    bool tessellation_shader_support;
    bool compute_shader_support;
    uint32_t max_texture_size;
    uint32_t max_texture_array_count;
} fxSystemInfo;

typedef struct fxCfg {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);
    void* usr_fn_address;
    fxFn (*fn_address)(void* usr, const char* name);
} fxCfg;

FX_API fxCtx* fx(fxCfg* cfg, fxSystemInfo* info);
FX_API void fx_destroy(fxCtx* ctx);
FX_API void fx_submit(fxCtx* ctx, fxCmdBuffer** cmd_buffers, uint32_t count);

FX_API fxPipelineId fx_pipeline(fxCtx* ctx, fxPipelineCfg* cfg);
FX_API void fx_pipeline_destroy(fxCtx* ctx, fxPipelineId pipeline);

FX_API fxPassId fx_pass(fxCtx* ctx, fxPassCfg* cfg);
FX_API void fx_pass_destroy(fxCtx* ctx, fxPassId pass);

FX_API fxBufferId fx_buffer(fxCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size);
FX_API void fx_buffer_destroy(fxCtx* ctx, fxBufferId buffer);
FX_API void fx_buffer_update(fxCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset);

FX_API fxTextureId fx_texture(fxCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes);
FX_API void fx_texture_destroy(fxCtx* ctx, fxTextureId texture);
FX_API void fx_texture_update(fxCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region);

FX_API fxSamplerId fx_sampler(fxCtx* ctx, fxSamplerCfg* cfg);
FX_API void fx_sampler_destroy(fxCtx* ctx, fxSamplerId sampler);

FX_API fxShaderId fx_shader(fxCtx* ctx, fxShaderCfg* cfg);
FX_API void fx_shader_destroy(fxCtx* ctx, fxShaderId shader);

FX_API fxCmdBuffer* fx_cmd_buffer(fxCtx* ctx);
FX_API void fx_cmd_buffer_destroy(fxCtx* ctx, fxCmdBuffer* cmd_buffer);
FX_API void fx_cmd_buffer_reset(fxCmdBuffer* cmd_buffer);

FX_API void fx_cmd_begin_pass_default(fxCmdBuffer* cmd_buffer, fxPassOp* op, uint32_t width, uint32_t height);
FX_API void fx_cmd_begin_pass_default_clear(fxCmdBuffer* cmd_buffer, uint32_t width, uint32_t height);
FX_API void fx_cmd_begin_pass(fxCmdBuffer* cmd_buffer, fxPassId pass, fxPassOp* ops);
FX_API void fx_cmd_end_pass(fxCmdBuffer* cmd_buffer);

FX_API void fx_cmd_viewport(fxCmdBuffer* cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
FX_API void fx_cmd_scissor(fxCmdBuffer* cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

FX_API void fx_cmd_bind_pipeline(fxCmdBuffer* cmd_buffer, fxPipelineId pipeline);
FX_API void fx_cmd_bind_vertex_buffers(fxCmdBuffer* cmd_buffer, fxBufferId* buffers, uint8_t count);
FX_API void fx_cmd_bind_index_buffer(fxCmdBuffer* cmd_buffer, fxBufferId index_buffer, fxIndexKind kind);
FX_API void fx_cmd_bind_uniform_buffer(fxCmdBuffer* cmd_buffer, fxBufferId uniform_buffer, uint8_t index, uint32_t size, uint32_t offset);
FX_API void fx_cmd_bind_textures(fxCmdBuffer* cmd_buffer, fxTextureId* textures, uint8_t count);
FX_API void fx_cmd_bind_samplers(fxCmdBuffer* cmd_buffer, fxSamplerId* samplers, uint8_t count);
FX_API void fx_cmd_bind_texture_units(fxCmdBuffer* cmd_buffer, fxTextureId* textures, uint8_t* units, uint8_t count);
FX_API void fx_cmd_bind_sampler_units(fxCmdBuffer* cmd_buffer, fxSamplerId* samplers, uint8_t* units, uint8_t count);

FX_API void fx_cmd_buffer_update(fxCmdBuffer* cmd_buffer, fxBufferId buffer, void* data, uint16_t size, uint16_t offset);
FX_API void fx_cmd_buffer_copy(fxCmdBuffer* cmd_buffer, fxBufferId src, fxBufferId dst, uint32_t src_offset, uint32_t dst_offset, uint32_t size);

FX_API void fx_cmd_texture_copy(fxCmdBuffer* cmd_buffer, fxTextureId src, fxTextureId dst, fxTextureRegion* region);

FX_API void fx_cmd_draw(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_vertex);
FX_API void fx_cmd_draw_indexed(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex);
FX_API void fx_cmd_draw_instanced(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_vertex, uint32_t instance_count);
FX_API void fx_cmd_draw_instanced_indexed(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex, uint32_t instance_count);

#if defined(__cplusplus)
}
#endif

#endif

#if defined(FX_IMPL)

// uint32_t index: 12;
// uint32_t generation: 14;
// uint32_t kind: 6;

typedef enum fxIdKind {
    FX_ID_KIND_PIPELINE,
    FX_ID_KIND_PASS,
    FX_ID_KIND_BUFFER,
    FX_ID_KIND_TEXTURE,
    FX_ID_KIND_SAMPLER,
    FX_ID_KIND_SHADER,
    FX_ID_KIND_COUNT
} fxIdKind;

#define FX_ID_INDEX_SHIFT (0)
#define FX_ID_INDEX_MASK (0x00000FFF)
#define FX_ID_GENERATION_SHIFT (12)
#define FX_ID_GENERATION_MASK (0x03FFF000)
#define FX_ID_KIND_SHIFT (27)
#define FX_ID_KIND_MASK (0xFC000000)

#define FX_ID_INDEX(id) (((id) & FX_ID_INDEX_MASK) >> FX_ID_INDEX_SHIFT)
#define FX_ID_GENERATION(id) (((id) & FX_ID_GENERATION_MASK) >> FX_ID_GENERATION_SHIFT)
#define FX_ID_KIND(id) (((id) & FX_ID_KIND_MASK) >> FX_ID_KIND_SHIFT)

#define FX_ID(index, generation, kind)                                                                                  \
    ((((index) << FX_ID_INDEX_SHIFT) & FX_ID_INDEX_MASK) |                                                              \
     (((generation) << FX_ID_GENERATION_SHIFT) & FX_ID_GENERATION_MASK) |                                               \
     (((kind) << FX_ID_KIND_SHIFT) & FX_ID_KIND_MASK))

#if !defined(FX_ID_INCREMENT)
#define FX_ID_INCREMENT(id) FX_ID(FX_ID_INDEX(id), FX_ID_GENERATION(id) + 1, FX_ID_KIND(id))
#endif

#if !defined(FX_ID_FROM_PTR)
#define FX_ID_FROM_PTR(ptr, ptrs) FX_ID(FX_INDEX_FROM_PTR(ptr, ptrs), 0, 0);
#endif

#if !defined(FX_INDEX_FROM_PTR)
#define FX_INDEX_FROM_PTR(ptr, ptrs) ((uint64_t) (((ptr) - (ptrs) + 1)))
#endif

#if !defined(FX_PTR_FROM_ID)
#define FX_PTR_FROM_ID(ptrs, id) (&(ptrs)[FX_ID_INDEX(id) - 1])
#endif

#if !defined(FX_ASSERT)
#include <assert.h>
#define FX_ASSERT assert
#endif

#if !defined(FX_MALLOC)
#include <stdlib.h>
#define FX_MALLOC malloc
#define FX_FREE free
#endif

#if !defined(FX_MEMSET)
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#define FX_MEMSET __builtin_memset
#else
#include <string.h>
#define FX_MEMSET memset
#endif
#endif

#if !defined(FX_MEMCOPY)
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#define FX_MEMCOPY __builtin_memcpy
#else
#include <string.h>
#define FX_MEMCOPY memcpy
#endif
#endif

#if !defined(FX_COUNT_OF)
#define FX_COUNT_OF(a) (sizeof(a) / sizeof((a)[0]))
#endif

#if !defined(FX_MIN)
#define FX_MIN(a, b) ((a) < (b) ? (a): (b))
#endif

#if !defined(FX_MAX)
#define FX_MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#if !defined(FX_CLAMP)
#define FX_CLAMP(a, min, max) (_FX_MAX((min), _FX_MIN((a), (max))))
#endif

static const char* _FX_SHADER_STAGE_NAME[] = {
    "Vertex",
    "Tessellation Control",
    "Tessellation Evaluation",
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

static fxPoolAllocator _fx_pool_allocator(void* data, uint64_t item_count, uint64_t item_size) {
    FX_ASSERT(data != NULL);
    FX_ASSERT(item_count > 0);
    FX_ASSERT(item_size >= sizeof(uintptr_t));

    fxPoolAllocator res;
    res.data = data;

    void* curr = data;
    for(uint64_t i = 0; i < (item_count - 1); i++) {
        uintptr_t* next = (uintptr_t*) curr;
        *next = ((uintptr_t) curr) + item_size;
        curr = (void*) (((uint8_t*) curr) + item_size);
    }

    uintptr_t* end = (uintptr_t*) curr;
    *end = (uintptr_t) NULL;

    res.size = item_count * item_size;
    res.used = 0;
    res.item_size = item_size;
    res.freelist = res.data;
    return res;
}

static void* _fx_pool_allocator_alloc(fxPoolAllocator* allocator) {
    FX_ASSERT(allocator != NULL);
    void* res = NULL;
    if(allocator->freelist) {
        uint64_t next = *((uint64_t*) allocator->freelist);
        res = allocator->freelist;
        allocator->freelist = (void**) next;
        allocator->used += allocator->item_size;
    }
    return res;
}

static void _fx_pool_allocator_dealloc(fxPoolAllocator* allocator, void* ptr) {
    FX_ASSERT(allocator != NULL);
    FX_ASSERT(ptr != NULL);
    FX_ASSERT(allocator->used > 0);
    *((void**) ptr) = allocator->freelist;
    allocator->freelist = ((void**) ptr);
    allocator->used -= allocator->item_size;
}

typedef enum fxCmdBufferState {
    FX_CMD_BUFFER_STATE_INVALID,
    FX_CMD_BUFFER_STATE_INACTIVE,
    FX_CMD_BUFFER_STATE_ACTIVE,
    FX_CMD_BUFFER_STATE_PENDING,
    FX_CMD_BUFFER_STATE_COUNT
} fxCmdBufferState;

struct fxCmdBuffer {
    fxCmdBufferState state;
    uint32_t used;
    uint8_t cmds[FX_CONFIG_CMD_BUFFER_CMD_MAX];
};

typedef struct fxIdPtr {
    fxId id;
    void* ptr;
} fxIdPtr;

typedef struct fxBackendCtx fxBackendCtx;

static void* _fx_backend(fxCfg* cfg, fxSystemInfo* info);
static void _fx_backend_destroy(fxBackendCtx* ctx);
static fxPipelineId _fx_backend_pipeline(fxBackendCtx* ctx, fxPipelineCfg* cfg);
static void _fx_backend_pipeline_destroy(fxBackendCtx* ctx, fxPipelineId pipeline);
static fxBufferId _fx_backend_buffer(fxBackendCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size);
static void _fx_backend_buffer_destroy(fxBackendCtx* ctx, fxBufferId buffer);
static void _fx_backend_buffer_update(fxBackendCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset);
static fxShaderId _fx_backend_shader(fxBackendCtx* ctx, fxShaderCfg* cfg);
static void _fx_backend_shader_destroy(fxBackendCtx* ctx, fxShaderId shader);
static fxTextureId _fx_backend_texture(fxBackendCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes);
static void _fx_backend_texture_destroy(fxBackendCtx* ctx, fxTextureId texture);
static void _fx_backend_texture_update(fxBackendCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region);
static fxSamplerId _fx_backend_sampler(fxBackendCtx* ctx, fxSamplerCfg* cfg);
static void _fx_backend_sampler_destroy(fxBackendCtx* ctx, fxSamplerId sampler);
static fxPassId _fx_backend_pass(fxBackendCtx* ctx, fxPassCfg* cfg);
static void _fx_backend_pass_destroy(fxBackendCtx* ctx, fxPassId pass);
static void _fx_backend_submit(fxBackendCtx* ctx, fxCmdBuffer* cmd_buffer);

struct fxCtx {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    fxCmdBuffer cmd_buffers[FX_CONFIG_CMD_BUFFER_MAX];
    fxPoolAllocator cmd_buffer_allocator;

    fxIdPtr ids[FX_CONFIG_TEXTURE_MAX + FX_CONFIG_BUFFER_MAX + + FX_CONFIG_SHADER_MAX + FX_CONFIG_PIPELINE_MAX + FX_CONFIG_PASS_MAX];
    fxPoolAllocator id_allocator;

    fxBackendCtx* backend;
};

//static fxId _fx_id_alloc(fxCtx ctx, uint32_t kind, void* ptr) {
//    FX_ASSERT(ctx != NULL);
//    FX_ASSERT(ptr != NULL);
//    fxIdPtr* id_ptr = _fx_pool_allocator_alloc(&ctx->id_allocator);
//    uint32_t index = FX_INDEX_FROM_PTR(id_ptr, ctx->ids);
//    uint32_t generation = FX_ID_GENERATION(id_ptr->id) + 1;
//    fxId id = FX_ID(index, generation, kind);
//    id_ptr->id = id;
//    id_ptr->ptr = ptr;
//    return id;
//}
//
//static void _fx_id_dealloc(fxCtx ctx, fxId id) {
//    FX_ASSERT(ctx != NULL);
//    FX_ASSERT(id != FX_ID_INVALID);
//    fxIdPtr* id_ptr = &ctx->ids[FX_ID_INDEX(id)];
//    FX_ASSERT(FX_ID_INDEX(id_ptr->id) == FX_ID_INDEX(id));
//    FX_ASSERT(FX_ID_GENERATION(id_ptr->id) == FX_ID_GENERATION(id));
//    FX_ASSERT(FX_ID_KIND(id_ptr->id) == FX_ID_KIND(id));
//    _fx_pool_allocator_dealloc(&ctx->id_allocator, id_ptr);
//}

static void _fx_null_log(void* usr, const char* fmt, ...) {
    (void) usr;
    (void) fmt;
}

fxCtx* fx(fxCfg* cfg, fxSystemInfo* info) {
    fxCtx* res = (fxCtx*) FX_MALLOC(sizeof(fxCtx));
    FX_MEMSET(res, 0, sizeof(fxCtx));
    cfg->log = cfg->log ? cfg->log: _fx_null_log;
    res->usr = cfg->usr;
    res->log = cfg->log;
    res->cmd_buffer_allocator = _fx_pool_allocator(res->cmd_buffers, FX_COUNT_OF(res->cmd_buffers), sizeof(fxCmdBuffer));
    res->id_allocator = _fx_pool_allocator(res->ids, FX_COUNT_OF(res->ids), sizeof(fxIdPtr));
    res->backend = _fx_backend(cfg, info);
    return res;
}

void fx_destroy(fxCtx* ctx) {
    _fx_backend_destroy(ctx->backend);
    FX_MEMSET(ctx, 0, sizeof(fxCtx));
}

void fx_submit(fxCtx* ctx, fxCmdBuffer** cmd_buffers, uint32_t count) {
    for(uint32_t i = 0; i < count; i++) {
        FX_ASSERT(cmd_buffers[i]->state == FX_CMD_BUFFER_STATE_INACTIVE);
        cmd_buffers[i]->state = FX_CMD_BUFFER_STATE_PENDING;
        _fx_backend_submit(ctx->backend, cmd_buffers[i]);
        cmd_buffers[i]->state = FX_CMD_BUFFER_STATE_INACTIVE;
    }
}

fxPipelineId fx_pipeline(fxCtx* ctx, fxPipelineCfg* cfg) {
    return _fx_backend_pipeline(ctx->backend, cfg);
}

void fx_pipeline_destroy(fxCtx* ctx, fxPipelineId pipeline) {
    _fx_backend_pipeline_destroy(ctx->backend, pipeline);
}

fxPassId fx_pass(fxCtx* ctx, fxPassCfg* cfg) {
    return _fx_backend_pass(ctx->backend, cfg);
}

void fx_pass_destroy(fxCtx* ctx, fxPassId pass) {
    _fx_backend_pass_destroy(ctx->backend, pass);
}

fxBufferId fx_buffer(fxCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size) {
    return _fx_backend_buffer(ctx->backend, cfg, data, size);
}

void fx_buffer_destroy(fxCtx* ctx, fxBufferId buffer) {
    _fx_backend_buffer_destroy(ctx->backend, buffer);
}

void fx_buffer_update(fxCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset) {
    _fx_backend_buffer_update(ctx->backend, buffer, data, size, offset);
}

fxTextureId fx_texture(fxCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes) {
    return _fx_backend_texture(ctx->backend, cfg, datas, sizes);
}

void fx_texture_destroy(fxCtx* ctx, fxTextureId texture) {
    _fx_backend_texture_destroy(ctx->backend, texture);
}

void fx_texture_update(fxCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region) {
    _fx_backend_texture_update(ctx->backend, texture, data, region);
}

fxSamplerId fx_sampler(fxCtx* ctx, fxSamplerCfg* cfg) {
    return _fx_backend_sampler(ctx->backend, cfg);
}

void fx_sampler_destroy(fxCtx* ctx, fxSamplerId sampler) {
    _fx_backend_sampler_destroy(ctx->backend, sampler);
}

fxShaderId fx_shader(fxCtx* ctx, fxShaderCfg* cfg) {
    return _fx_backend_shader(ctx->backend, cfg);
}

void fx_shader_destroy(fxCtx* ctx, fxShaderId shader) {
    _fx_backend_shader_destroy(ctx->backend, shader);
}

typedef uint8_t fxCmdKind;

enum {
    FX_CMD_KIND_BEGIN_PASS,
    FX_CMD_KIND_END_PASS,
    FX_CMD_KIND_VIEWPORT,
    FX_CMD_KIND_SCISSOR,
    FX_CMD_KIND_BIND_PIPELINE,
    FX_CMD_KIND_BIND_VERTEX_BUFFERS,
    FX_CMD_KIND_BIND_INDEX_BUFFER,
    FX_CMD_KIND_BIND_UNIFORM_BUFFER,
    FX_CMD_KIND_BUFFER_UPDATE,
    FX_CMD_KIND_BUFFER_COPY,
    FX_CMD_KIND_BIND_TEXTURES,
    FX_CMD_KIND_BIND_SAMPLERS,
    FX_CMD_KIND_TEXTURE_COPY,
    FX_CMD_KIND_TEXTURE_BLIT,
    FX_CMD_KIND_TEXTURE_UPDATE,
    FX_CMD_KIND_UPDATE_UNIFORMS,
    FX_CMD_KIND_DRAW,
    FX_CMD_KIND_DRAW_INDEXED,
    FX_CMD_KIND_DRAW_INSTANCED,
    FX_CMD_KIND_DRAW_INSTANCED_INDEXED,
    FX_CMD_KIND_COUNT
};

typedef struct fxCmdHeader {
    fxCmdKind kind;
    uint16_t size;
} fxCmdHeader;

typedef struct fxCmdBeginPass {
    uint32_t width, height;
    fxPassId pass;
    fxPassOp ops;
} fxCmdBeginPass;

typedef struct fxCmdEndPass {
    fxPassId pass;
} fxCmdEndPass;

typedef struct fxCmdViewport {
    uint16_t x, y, width, height;
} fxCmdViewport;

typedef struct fxCmdScissor {
    uint16_t x, y, width, height;
} fxCmdScissor;

typedef struct fxCmdBindPipeline {
    fxPipelineId pipeline;
} fxCmdBindPipeline;

typedef struct fxCmdBindVertexBuffers {
    fxBufferId vertex_buffers[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    uint8_t count;
} fxCmdBindVertexBuffers;

typedef struct fxCmdBindIndexBuffer {
    fxBufferId index_buffer;
    fxIndexKind index_kind;
} fxCmdBindIndexBuffer;

typedef struct fxCmdBindUniformBuffer {
    fxBufferId uniform_buffer;
    uint8_t index;
    uint32_t size;
    uint32_t offset;
} fxCmdBindUniformBuffer;

typedef struct fxCmdBindTextures {
    fxTextureId textures[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t units[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t count;
} fxCmdBindTextures;

typedef struct fxCmdBindSamplers {
    fxSamplerId samplers[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t units[FX_CONFIG_TEXTURE_BINDING_MAX];
    uint8_t count;
} fxCmdBindSamplers;

typedef struct fxCmdUpdateUniforms {
    fxShaderStage stage;
    uint16_t size;
} fxCmdUpdateUniforms;

typedef struct fxCmdBufferUpdate {
    fxBufferId buffer;
    uint32_t size;
    uint32_t offset;
} fxCmdBufferUpdate;

typedef struct fxCmdBufferCopy {
    fxBufferId src;
    fxBufferId dst;
    uint32_t src_offset;
    uint32_t dst_offset;
    uint32_t size;
} fxCmdBufferCopy;

typedef struct fxCmdTextureCopy {
    fxTextureId src;
    fxTextureId dst;
    fxTextureRegion region;
} fxCmdTextureCopy;

typedef struct fxCmdTextureBlit {
    fxTextureId src;
    fxTextureId dst;
    fxTextureRegion region;
} fxCmdTextureBlit;

typedef struct fxCmdTextureUpdate {
    fxTextureId texture;
    fxTextureRegion region;
} fxCmdTextureUpdate;

typedef struct fxCmdDraw {
    fxPrimitiveKind primitive;
    uint32_t count;
    uint32_t first_index;
    uint32_t first_vertex;
} fxCmdDraw;

typedef struct fxCmdDrawInstanced {
    fxPrimitiveKind primitive;
    uint32_t count;
    uint32_t first_index;
    uint32_t first_vertex;
    uint32_t instance_count;
} fxCmdDrawInstanced;

fxCmdBuffer* fx_cmd_buffer(fxCtx* ctx) {
    fxCmdBuffer* res = _fx_pool_allocator_alloc(&ctx->cmd_buffer_allocator);
    FX_ASSERT(res != NULL);
    res->state = FX_CMD_BUFFER_STATE_INACTIVE;
    res->used = 0;
    return res;
}

void fx_cmd_buffer_destroy(fxCtx* ctx, fxCmdBuffer* cmd_buffer) {
    _fx_pool_allocator_dealloc(&ctx->cmd_buffer_allocator, cmd_buffer);
}

void fx_cmd_buffer_reset(fxCmdBuffer* cmd_buffer) {
    FX_ASSERT(cmd_buffer->state != FX_CMD_BUFFER_STATE_PENDING);
    cmd_buffer->state = FX_CMD_BUFFER_STATE_INACTIVE;
    cmd_buffer->used = 0;
}

static uint8_t* _fx_cmd(fxCmdBuffer* cmd_buffer, fxCmdKind kind, uint16_t size) {
    FX_ASSERT(cmd_buffer->state == FX_CMD_BUFFER_STATE_ACTIVE);
    FX_ASSERT((cmd_buffer->used + sizeof(fxCmdHeader) + size) < FX_CONFIG_CMD_BUFFER_CMD_MAX);

    fxCmdHeader* res = (fxCmdHeader*) (cmd_buffer->cmds + cmd_buffer->used);
    FX_MEMSET(res, 0, sizeof(fxCmdHeader) + size);
    res->kind = kind;
    res->size = size;
    cmd_buffer->used += sizeof(fxCmdHeader) + size;
    return (uint8_t*) (res + 1);
}

void fx_cmd_begin_pass_default(fxCmdBuffer* cmd_buffer, fxPassOp* ops, uint32_t width, uint32_t height) {
    FX_ASSERT(cmd_buffer->state == FX_CMD_BUFFER_STATE_INACTIVE);
    FX_ASSERT(ops != NULL);
    FX_ASSERT(width > 0);
    FX_ASSERT(height > 0);
    cmd_buffer->state = FX_CMD_BUFFER_STATE_ACTIVE;

    fxCmdBeginPass* cmd = (fxCmdBeginPass*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BEGIN_PASS, sizeof(fxCmdBeginPass));
    cmd->pass = FX_ID_INVALID;
    cmd->width = width;
    cmd->height = height;
    FX_MEMCOPY(&cmd->ops, ops, sizeof(fxPassOp));
}

void fx_cmd_begin_pass_default_clear(fxCmdBuffer* cmd_buffer, uint32_t width, uint32_t height) {
    fxPassOp ops;
    ops.colours[0].kind = FX_PASS_OP_KIND_CLEAR;
    ops.colours[0].clear = 0x000000FF;
    ops.depth.kind = FX_PASS_OP_KIND_CLEAR;
    ops.depth.clear = 1.0f;
    ops.stencil.kind = FX_PASS_OP_KIND_CLEAR;
    ops.stencil.clear = 0;
    fx_cmd_begin_pass_default(cmd_buffer, &ops, width, height);
}

void fx_cmd_begin_pass(fxCmdBuffer* cmd_buffer, fxPassId pass, fxPassOp* ops) {
    FX_ASSERT(pass != FX_ID_INVALID);
    FX_ASSERT(pass < FX_CONFIG_BUFFER_MAX);
    FX_ASSERT(cmd_buffer->state == FX_CMD_BUFFER_STATE_INACTIVE);
    FX_ASSERT(ops != NULL);
    cmd_buffer->state = FX_CMD_BUFFER_STATE_ACTIVE;
    fxCmdBeginPass* cmd = (fxCmdBeginPass*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BEGIN_PASS, sizeof(fxCmdBeginPass));
    cmd->pass = pass;
    FX_MEMCOPY(&cmd->ops, ops, sizeof(fxPassOp));
}

void fx_cmd_end_pass(fxCmdBuffer* cmd_buffer) {
    fxCmdEndPass* cmd = (fxCmdEndPass*) _fx_cmd(cmd_buffer, FX_CMD_KIND_END_PASS, sizeof(fxCmdEndPass));
    (void) cmd;
    cmd_buffer->state = FX_CMD_BUFFER_STATE_INACTIVE;
}

void fx_cmd_viewport(fxCmdBuffer* cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    fxCmdViewport* cmd = (fxCmdViewport*) _fx_cmd(cmd_buffer, FX_CMD_KIND_VIEWPORT, sizeof(fxCmdViewport));
    cmd->x = x;
    cmd->y = y;
    cmd->width = width;
    cmd->height = height;
}

void fx_cmd_scissor(fxCmdBuffer* cmd_buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    fxCmdScissor* cmd = (fxCmdScissor*) _fx_cmd(cmd_buffer, FX_CMD_KIND_SCISSOR, sizeof(fxCmdScissor));
    cmd->x = x;
    cmd->y = y;
    cmd->width = width;
    cmd->height = height;
}

void fx_cmd_bind_pipeline(fxCmdBuffer* cmd_buffer, fxPipelineId pipeline) {
    FX_ASSERT(pipeline != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(pipeline) < FX_CONFIG_PIPELINE_MAX);
    fxCmdBindPipeline* cmd = (fxCmdBindPipeline*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_PIPELINE, sizeof(fxCmdBindPipeline));
    cmd->pipeline = pipeline;
}

void fx_cmd_bind_vertex_buffers(fxCmdBuffer* cmd_buffer, fxBufferId* buffers, uint8_t count) {
    FX_ASSERT(count < FX_CONFIG_VERTEX_BUFFER_BINDING_MAX);
#if defined(_DEBUG)
    for(uint32_t i = 0; i < count; i++) {
        FX_ASSERT(buffers[i] != FX_ID_INVALID);
        FX_ASSERT(FX_ID_INDEX(buffers[i]) < FX_CONFIG_BUFFER_MAX);
    }
#endif
    fxCmdBindVertexBuffers* cmd = (fxCmdBindVertexBuffers*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_VERTEX_BUFFERS, sizeof(fxCmdBindVertexBuffers));
    FX_MEMCOPY(cmd->vertex_buffers, buffers, count * sizeof(fxBufferId));
    cmd->count = count;
}

void fx_cmd_bind_index_buffer(fxCmdBuffer* cmd_buffer, fxBufferId index_buffer, fxIndexKind kind) {
    FX_ASSERT(index_buffer != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(index_buffer) < FX_CONFIG_BUFFER_MAX);
    fxCmdBindIndexBuffer* cmd = (fxCmdBindIndexBuffer*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_INDEX_BUFFER, sizeof(fxCmdBindIndexBuffer));
    cmd->index_buffer = index_buffer;
    cmd->index_kind = kind;
}

void fx_cmd_bind_uniform_buffer(fxCmdBuffer* cmd_buffer, fxBufferId uniform_buffer, uint8_t index, uint32_t size, uint32_t offset) {
    FX_ASSERT(uniform_buffer != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(uniform_buffer) < FX_CONFIG_BUFFER_MAX);
    fxCmdBindUniformBuffer* cmd = (fxCmdBindUniformBuffer*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_UNIFORM_BUFFER, sizeof(fxCmdBindUniformBuffer));
    cmd->uniform_buffer = uniform_buffer;
    cmd->index = index;
    cmd->size = size;
    cmd->offset = offset;
}

void fx_cmd_buffer_update(fxCmdBuffer* cmd_buffer, fxBufferId buffer, void* data, uint16_t size, uint16_t offset) {
    FX_ASSERT(buffer != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(buffer) < FX_CONFIG_BUFFER_MAX);
    fxCmdBufferUpdate* cmd = (fxCmdBufferUpdate*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BUFFER_UPDATE, sizeof(fxCmdBufferUpdate) + size);
    FX_MEMCOPY(cmd + 1, data, size);
    cmd->buffer = buffer;
    cmd->size = size;
    cmd->offset = offset;
}

void fx_cmd_buffer_copy(fxCmdBuffer* cmd_buffer, fxBufferId src, fxBufferId dst, uint32_t src_offset, uint32_t dst_offset, uint32_t size) {
    FX_ASSERT(src != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(src) < FX_CONFIG_TEXTURE_MAX);
    FX_ASSERT(dst != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(dst) < FX_CONFIG_TEXTURE_MAX);
    fxCmdBufferCopy* cmd = (fxCmdBufferCopy*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BUFFER_COPY, sizeof(fxCmdBufferCopy));
    cmd->src = src;
    cmd->dst = dst;
    cmd->src_offset = src_offset;
    cmd->dst_offset = dst_offset;
    cmd->size = size;
}

void fx_cmd_bind_textures(fxCmdBuffer* cmd_buffer, fxTextureId* textures, uint8_t count) {
    fx_cmd_bind_texture_units(cmd_buffer, textures, NULL, count);
}

void fx_cmd_bind_samplers(fxCmdBuffer* cmd_buffer, fxSamplerId* samplers, uint8_t count) {
    fx_cmd_bind_sampler_units(cmd_buffer, samplers, NULL, count);
}

void fx_cmd_bind_texture_units(fxCmdBuffer* cmd_buffer, fxTextureId* textures, uint8_t* units, uint8_t count) {
    FX_ASSERT(count < FX_CONFIG_TEXTURE_BINDING_MAX);
#if defined(_DEBUG)
    for(uint32_t i = 0; i < count; i++) {
        FX_ASSERT(textures[i] != FX_ID_INVALID);
        FX_ASSERT(FX_ID_INDEX(textures[i]) < FX_CONFIG_TEXTURE_MAX);
    }
#endif
    fxCmdBindTextures* cmd = (fxCmdBindTextures*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_TEXTURES, sizeof(fxCmdBindTextures));
    FX_MEMCOPY(cmd->textures, textures, count * sizeof(fxTextureId));
    if(units) {
        FX_MEMCOPY(cmd->units, units, count * sizeof(uint8_t));
    } else {
        FX_MEMSET(cmd->units, (uint8_t) -1, count);
    }
    cmd->count = count;
}

void fx_cmd_bind_sampler_units(fxCmdBuffer* cmd_buffer, fxSamplerId* samplers, uint8_t* units, uint8_t count) {
    FX_ASSERT(count < FX_CONFIG_TEXTURE_BINDING_MAX);
#if defined(_DEBUG)
    for(uint32_t i = 0; i < count; i++) {
        FX_ASSERT(samplers[i] != FX_ID_INVALID);
        FX_ASSERT(FX_ID_INDEX(samplers[i]) < FX_CONFIG_TEXTURE_MAX);
    }
#endif
    fxCmdBindSamplers* cmd = (fxCmdBindSamplers*) _fx_cmd(cmd_buffer, FX_CMD_KIND_BIND_SAMPLERS, sizeof(fxCmdBindSamplers));
    FX_MEMCOPY(cmd->samplers, samplers, count * sizeof(fxSamplerId));
    if(units) {
        FX_MEMCOPY(cmd->units, units, count * sizeof(uint8_t));
    } else {
        FX_MEMSET(cmd->units, (uint8_t) -1, count);
    }
    cmd->count = count;
}

void fx_cmd_texture_copy(fxCmdBuffer* cmd_buffer, fxTextureId src, fxTextureId dst, fxTextureRegion* region) {
    FX_ASSERT(src != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(src) < FX_CONFIG_TEXTURE_MAX);
    FX_ASSERT(dst != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(dst) < FX_CONFIG_TEXTURE_MAX);
    fxCmdTextureCopy* cmd = (fxCmdTextureCopy*) _fx_cmd(cmd_buffer, FX_CMD_KIND_TEXTURE_COPY, sizeof(fxCmdTextureCopy));
    cmd->src = src;
    cmd->dst = dst;
    cmd->region = *region;
}

void fx_cmd_texture_blit(fxCmdBuffer* cmd_buffer, fxTextureId src, fxTextureId dst, fxTextureRegion* region) {
    FX_ASSERT(src != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(src) < FX_CONFIG_TEXTURE_MAX);
    FX_ASSERT(dst != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(dst) < FX_CONFIG_TEXTURE_MAX);
    fxCmdTextureBlit* cmd = (fxCmdTextureBlit*) _fx_cmd(cmd_buffer, FX_CMD_KIND_TEXTURE_BLIT, sizeof(fxCmdTextureBlit));
    cmd->src = src;
    cmd->dst = dst;
    cmd->region = *region;
}

void fx_cmd_texture_update(fxCmdBuffer* cmd_buffer, fxTextureId texture, void* data, fxTextureRegion* region) {
    FX_ASSERT(texture != FX_ID_INVALID);
    FX_ASSERT(FX_ID_INDEX(texture) < FX_CONFIG_TEXTURE_MAX);
    FX_ASSERT(!"Unimplemented");
    (void) data;
    fxCmdTextureUpdate* cmd = (fxCmdTextureUpdate*) _fx_cmd(cmd_buffer, FX_CMD_KIND_TEXTURE_UPDATE, sizeof(fxCmdTextureUpdate));
    cmd->texture = texture;
    cmd->region = *region;
}

void fx_cmd_draw(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_vertex) {
    fxCmdDraw* cmd = (fxCmdDraw*) _fx_cmd(cmd_buffer, FX_CMD_KIND_DRAW, sizeof(fxCmdDraw));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_vertex = first_vertex;
}

void fx_cmd_draw_indexed(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex) {
    fxCmdDraw* cmd = (fxCmdDraw*) _fx_cmd(cmd_buffer, FX_CMD_KIND_DRAW_INDEXED, sizeof(fxCmdDraw));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_index = first_index;
    cmd->first_vertex = first_vertex;
}

void fx_cmd_draw_instanced(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_vertex, uint32_t instance_count) {
    fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) _fx_cmd(cmd_buffer, FX_CMD_KIND_DRAW_INSTANCED, sizeof(fxCmdDrawInstanced));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_vertex = first_vertex;
    cmd->instance_count = instance_count;
}

void fx_cmd_draw_instanced_indexed(fxCmdBuffer* cmd_buffer, fxPrimitiveKind primitive, uint32_t count, uint32_t first_index, uint32_t first_vertex,
    uint32_t instance_count) {
    fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) _fx_cmd(cmd_buffer, FX_CMD_KIND_DRAW_INSTANCED_INDEXED, sizeof(fxCmdDrawInstanced));
    cmd->primitive = primitive;
    cmd->count = count;
    cmd->first_index = first_index;
    cmd->first_vertex = first_vertex;
    cmd->instance_count = instance_count;
}

#if defined(FX_GL45_IMPL)
#include "fx.gl45.h"
#elif defined(FX_GL33_IMPL)
#include "fx.gl33.h"
#else
#include "fx.null.h"
#endif

#endif

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
