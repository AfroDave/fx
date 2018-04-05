#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../fx.h"

#include "kj_math.h"

#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void fn_log(void* usr, const char* fmt, ...) {
    (void) usr;
    va_list v;
    va_start(v, fmt);
    vfprintf(stderr, fmt, v);
    va_end(v);
}

fxFn fn_address(void* usr, const char* name) {
    (void) usr;
    fxFn res = (fxFn) glfwGetProcAddress(name);
    return res;
}

#define OFFSET_OF(s, m) ((uint64_t) (&(((s*) 0)->m)))
#define COUNT_OF(a) (sizeof(a) / sizeof((a)[0]))

#include "example_common.h"

int32_t main(void) {
    const int32_t WIDTH = 512;
    const int32_t HEIGHT = 512;

    example(WIDTH, HEIGHT, "Example Textured Cube");

    fxCtx* ctx;
    fxSystemInfo info; {
        fxCfg cfg = {};
        cfg.log = fn_log;
        cfg.fn_address = fn_address;
        ctx = fx(&cfg, &info);
    }

    typedef struct Vertex {
        float position[3];
        float texcoord0[2];
        uint32_t colour0;
    } Vertex;

    Vertex vertices[] = {
        {{ -1.0f, -1.0f, -1.0f }, { 0.0f, 0.0f }, 0xFF0000FF },
        {{  1.0f, -1.0f, -1.0f }, { 1.0f, 0.0f }, 0xFF00FF00 },
        {{  1.0f,  1.0f, -1.0f }, { 1.0f, 1.0f }, 0xFFFF0000 },
        {{ -1.0f,  1.0f, -1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f, -1.0f,  1.0f }, { 0.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f, -1.0f,  1.0f }, { 1.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f,  1.0f,  1.0f }, { 1.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f,  1.0f,  1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f, -1.0f, -1.0f }, { 0.0f, 0.0f }, 0xFFFFFFFF },
        {{ -1.0f,  1.0f, -1.0f }, { 1.0f, 0.0f }, 0xFFFFFFFF },
        {{ -1.0f,  1.0f,  1.0f }, { 1.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f, -1.0f,  1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
        {{  1.0f, -1.0f, -1.0f }, { 0.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f,  1.0f, -1.0f }, { 1.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f,  1.0f,  1.0f }, { 1.0f, 1.0f }, 0xFFFFFFFF },
        {{  1.0f, -1.0f,  1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f, -1.0f, -1.0f }, { 0.0f, 0.0f }, 0xFFFFFFFF },
        {{ -1.0f, -1.0f,  1.0f }, { 1.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f, -1.0f,  1.0f }, { 1.0f, 1.0f }, 0xFFFFFFFF },
        {{  1.0f, -1.0f, -1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
        {{ -1.0f,  1.0f, -1.0f }, { 0.0f, 0.0f }, 0xFFFFFFFF },
        {{ -1.0f,  1.0f,  1.0f }, { 1.0f, 0.0f }, 0xFFFFFFFF },
        {{  1.0f,  1.0f,  1.0f }, { 1.0f, 1.0f }, 0xFFFFFFFF },
        {{  1.0f,  1.0f, -1.0f }, { 0.0f, 1.0f }, 0xFFFFFFFF },
    };

    uint16_t indices[] = {
        0, 1, 2,
        0, 2, 3,
        6, 5, 4,
        7, 6, 4,
        8, 9, 10,
        8, 10, 11,
        14, 13, 12,
        15, 14, 12,
        16, 17, 18,
        16, 18, 19,
        22, 21, 20,
        23, 22, 20,
    };

    fxBufferId vbo; {
        fxBufferCfg cfg = {};
        cfg.kind = FX_BUFFER_KIND_VERTEX;
        cfg.size = sizeof(vertices);
        vbo = fx_buffer(ctx, &cfg, vertices, sizeof(vertices));
    }

    fxBufferId ibo; {
        fxBufferCfg cfg = {};
        cfg.kind = FX_BUFFER_KIND_INDEX;
        cfg.size = sizeof(indices);
        ibo = fx_buffer(ctx, &cfg, indices, sizeof(indices));
    }

    fxBufferId ubo; {
        fxBufferCfg cfg = {};
        cfg.kind = FX_BUFFER_KIND_UNIFORM;
        cfg.size = sizeof(kjMat4f);
        cfg.flags = FX_BUFFER_DYNAMIC;
        ubo = fx_buffer(ctx, &cfg, NULL, 0);
    }

    fxTextureId tex; {
        fxTextureCfg cfg = {};
        cfg.format = FX_FORMAT_R8UN;
        cfg.width = 8;
        cfg.height = 8;
        uint8_t checkerboard[8 * 8] = {
            0xBB, 0xBB, 0xBB, 0xBB, 0x66, 0x66, 0x66, 0x66,
            0xBB, 0xBB, 0xBB, 0xBB, 0x66, 0x66, 0x66, 0x66,
            0xBB, 0xBB, 0xBB, 0xBB, 0x66, 0x66, 0x66, 0x66,
            0xBB, 0xBB, 0xBB, 0xBB, 0x66, 0x66, 0x66, 0x66,
            0x66, 0x66, 0x66, 0x66, 0xBB, 0xBB, 0xBB, 0xBB,
            0x66, 0x66, 0x66, 0x66, 0xBB, 0xBB, 0xBB, 0xBB,
            0x66, 0x66, 0x66, 0x66, 0xBB, 0xBB, 0xBB, 0xBB,
            0x66, 0x66, 0x66, 0x66, 0xBB, 0xBB, 0xBB, 0xBB,
        };
        uint32_t sizes[] = { sizeof(checkerboard) };
        void* datas[] = { checkerboard };
        tex = fx_texture(ctx, &cfg, datas, sizes);
    }

    fxSamplerId sampler; {
        fxSamplerCfg cfg = {};
        cfg.wrap_u = FX_WRAP_MODE_CLAMP_TO_EDGE;
        cfg.wrap_v = FX_WRAP_MODE_CLAMP_TO_EDGE;
        sampler = fx_sampler(ctx, &cfg);
    }

    fxPipelineId pipeline; {
        fxShaderId vertex; {
            fxShaderCfg cfg = {};
            cfg.stage = FX_SHADER_STAGE_VERTEX;
            cfg.source =
                "#version 330 core\n"
                "#extension GL_ARB_explicit_uniform_location: enable\n"
                "#extension GL_ARB_shading_language_420pack: enable\n"
                "#extension GL_ARB_gpu_shader5: enable\n"
                "layout(location=0) in vec3 i_position;\n"
                "layout(location=1) in vec2 i_texcoord0;\n"
                "layout(location=2) in vec4 i_colour0;\n"
                "layout(binding=0, std140) uniform VS_IN {\n"
                "    mat4 u_mvp;\n"
                "};\n"
                "out VS_OUT {\n"
                "    vec2 f_texcoord0;\n"
                "    vec4 f_colour0;\n"
                "};\n"
                "out gl_PerVertex { vec4 gl_Position; };\n"
                "void main() {\n"
                "    f_texcoord0 = i_texcoord0;\n"
                "    f_colour0 = i_colour0;\n"
                "    gl_Position = u_mvp * vec4(i_position, 1.0f);\n"
                "}\n";
            vertex = fx_shader(ctx, &cfg);
        }
        fxShaderId fragment; {
            fxShaderCfg cfg = {};
            cfg.stage = FX_SHADER_STAGE_FRAGMENT;
            cfg.source =
                "#version 330 core\n"
                "#extension GL_ARB_explicit_uniform_location: enable\n"
                "#extension GL_ARB_shading_language_420pack: enable\n"
                "#extension GL_ARB_gpu_shader5: enable\n"
                "in VS_OUT {\n"
                "    vec2 f_texcoord0;\n"
                "    vec4 f_colour0;\n"
                "};\n"
                "uniform sampler2D u_sampler;\n"
                "out vec4 o_colour;\n"
                "void main() {\n"
                "    o_colour = vec4(vec3(texture2D(u_sampler, f_texcoord0).r * f_colour0), 1.0f);\n"
                "}\n";
            fragment = fx_shader(ctx, &cfg);
        }
        fxPipelineCfg cfg = {};
        cfg.raster.cull = FX_CULL_MODE_FRONT;
        cfg.depth_stencil.flags = FX_PIPELINE_DEPTH_STENCIL_DEPTH_TEST | FX_PIPELINE_DEPTH_STENCIL_DEPTH_WRITE;
        cfg.depth_stencil.depth_op = FX_COMPARE_OP_LESS;
        cfg.shader.vertex = vertex;
        cfg.shader.fragment = fragment;
        cfg.layouts[0].attribs[0] = (fxVertexAttrib) { 0, 0, "i_position", FX_FORMAT_R32G32B32F, FX_ATTRIB_SEMANTIC_POSITION, (uint32_t) OFFSET_OF(Vertex, position) };
        cfg.layouts[0].attribs[2] = (fxVertexAttrib) { 0, 1, "i_texcoord0", FX_FORMAT_R32G32F, FX_ATTRIB_SEMANTIC_TEXCOORD0, (uint32_t) OFFSET_OF(Vertex, texcoord0)  };
        cfg.layouts[0].attribs[1] = (fxVertexAttrib) { 0, 2, "i_colour0", FX_FORMAT_R8G8B8A8UN, FX_ATTRIB_SEMANTIC_COLOUR0, (uint32_t) OFFSET_OF(Vertex, colour0) };
        pipeline = fx_pipeline(ctx, &cfg);
    }

    fxCmdBuffer* cmd_buffer = fx_cmd_buffer(ctx);
    while(!example_should_close()) {
        int32_t width, height;
        glfwGetWindowSize(FX_EXAMPLE_WINDOW, &width, &height);

        kjMat4f proj = kj_mat4f_perspective(60.0f * KJ_D2R, (float) width / (float) height, 0.01f, 100.0f);
        kjMat4f view = kj_mat4f_look_at(kj_vec3f(0.0f, 1.5f, 4.0f), kj_vec3f_zero(), kj_vec3f(0.0f, 1.0f, 0.0f));
        kjMat4f model = kj_mat4f_rotate_y(glfwGetTime() * 0.1f);
        kjMat4f mvp = kj_mat4f_mul(kj_mat4f_mul(proj, view), model);

        fx_buffer_update(ctx, ubo, (void*) &mvp, sizeof(kjMat4f), 0);

        fx_cmd_begin_pass_default_clear(cmd_buffer, width, height);
        fx_cmd_viewport(cmd_buffer, 0, 0, width, height);
        fx_cmd_bind_pipeline(cmd_buffer, pipeline);
        fx_cmd_bind_vertex_buffers(cmd_buffer, &vbo, 1);
        fx_cmd_bind_index_buffer(cmd_buffer, ibo, FX_INDEX_KIND_U16);
        fx_cmd_bind_uniform_buffer(cmd_buffer, ubo, 0, sizeof(kjMat4f), 0);
        fx_cmd_bind_textures(cmd_buffer, &tex, 1);
        fx_cmd_bind_samplers(cmd_buffer, &sampler, 1);
        fx_cmd_draw_indexed(cmd_buffer, FX_PRIMITIVE_KIND_TRIANGLE_LIST, COUNT_OF(indices), 0, 0);
        fx_cmd_end_pass(cmd_buffer);

        fx_submit(ctx, &cmd_buffer, 1);

        fx_cmd_buffer_reset(cmd_buffer);

        glfwSwapBuffers(FX_EXAMPLE_WINDOW);
        glfwPollEvents();
    }

    glfwTerminate();
}

#define FX_IMPL
#include "../fx.h"

#define KJ_MATH_IMPL
#include "kj_math.h"
