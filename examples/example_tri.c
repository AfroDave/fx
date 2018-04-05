#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../fx.h"

#include <stdio.h>
#include <stdarg.h>

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

int32_t main(void) {
    const int32_t WIDTH = 512;
    const int32_t HEIGHT = 512;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* w = glfwCreateWindow(WIDTH, HEIGHT, "Example Tri", 0, 0);
    glfwMakeContextCurrent(w);
    glfwSwapInterval(1);

    fxCtx* ctx;
    fxSystemInfo info; {
        fxCfg cfg = {};
        cfg.log = fn_log;
        cfg.fn_address = fn_address;
        ctx = fx(&cfg, &info);
    }

    fxPipelineId pipeline; {
        fxShaderId vertex; {
            fxShaderCfg cfg = {};
            cfg.stage = FX_SHADER_STAGE_VERTEX;
            cfg.source =
                "#version 330 core\n"
                "#extension GL_ARB_shading_language_420pack: enable\n"
                "#extension GL_ARB_gpu_shader5: enable\n"
                "void main() {\n"
                "}\n";
            vertex = fx_shader(ctx, &cfg);
        }
        fxShaderId geometry; {
            fxShaderCfg cfg = {};
            cfg.stage = FX_SHADER_STAGE_GEOMETRY;
            cfg.source =
                "#version 330 core\n"
                "#extension GL_ARB_shading_language_420pack: enable\n"
                "#extension GL_ARB_gpu_shader5: enable\n"
                "layout(points) in;\n"
                "layout(triangle_strip, max_vertices = 3) out;\n"
                "out vec2 f_texcoord0;\n"
                "out gl_PerVertex { vec4 gl_Position; };\n"
                "void main() {\n"
                "    gl_Position = vec4(0.5f, 0.5f, 0.5f, 1.0f);\n"
                "    f_texcoord0 = vec2(1.0f, 1.0f);\n"
                "    EmitVertex();\n"
                "    gl_Position = vec4(-0.5f, 0.5f, 0.5f, 1.0f);\n"
                "    f_texcoord0 = vec2(0.0f, 1.0f);\n"
                "    EmitVertex();\n"
                "    gl_Position = vec4(0.0f, -0.5f, 0.5f, 1.0f);\n"
                "    f_texcoord0 = vec2(1.0f, 0.0f);\n"
                "    EmitVertex();\n"
                "    EndPrimitive();\n"
                "}\n";
            geometry = fx_shader(ctx, &cfg);
        }
        fxShaderId fragment; {
            fxShaderCfg cfg = {};
            cfg.stage = FX_SHADER_STAGE_FRAGMENT;
            cfg.source =
                "#version 330 core\n"
                "#extension GL_ARB_shading_language_420pack: enable\n"
                "#extension GL_ARB_gpu_shader5: enable\n"
                "in vec2 f_texcoord0;\n"
                "out vec4 o_colour;\n"
                "void main() {\n"
                "    o_colour = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
                "}\n";
            fragment = fx_shader(ctx, &cfg);
        }
        fxPipelineCfg cfg = {};
        cfg.shader.vertex = vertex;
        cfg.shader.geometry = geometry;
        cfg.shader.fragment = fragment;
        pipeline = fx_pipeline(ctx, &cfg);
    }

    fxCmdBuffer* cmd_buffer = fx_cmd_buffer(ctx);
    while(!glfwWindowShouldClose(w)) {
        int32_t width, height;
        glfwGetWindowSize(w, &width, &height);

        fx_cmd_begin_pass_default_clear(cmd_buffer, width, height);
        fx_cmd_viewport(cmd_buffer, 0, 0, width, height);
        fx_cmd_bind_pipeline(cmd_buffer, pipeline);
        fx_cmd_draw(cmd_buffer, FX_PRIMITIVE_KIND_POINT_LIST, 1, 0);
        fx_cmd_end_pass(cmd_buffer);

        fx_submit(ctx, &cmd_buffer, 1);

        fx_cmd_buffer_reset(cmd_buffer);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
}

#define FX_IMPL
#include "../fx.h"
