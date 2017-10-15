#! /usr/bin/env bash

CC='clang'
CFLAGS='-std=c99 -O0 -ggdb3 -Wall -Wextra -Wpedantic -Wno-gnu-empty-initializer -Wno-gnu-zero-variadic-macro-arguments -Wno-variadic-macros'

case ${1} in
    gl45)
        IMPL='gl45'
        CFLAGS="${CFLAGS} -DFX_GL45_IMPL"
        ;;
    gl33)
        IMPL='gl33'
        CFLAGS="${CFLAGS} -DFX_GL33_IMPL"
        ;;
    *)
        echo "Unknown Implementation: ${1}"
        exit
        ;;
esac


PLATFORM=$(uname -s)
case "${PLATFORM}" in
    Linux)
        LIBS='-lGL -lglfw3'
        PLATFORM='linux'
        ;;
    CYGWIN*|MINGW32*|MINGW64*|MSYS*)
        LIBS='-lkernel32 -lglfw3 -lgdi32'
        PLATFORM='win32'
        ;;
    *)
        echo "Unknown Platform: ${PLATFORM}"
        exit
        ;;
esac

${CC} ${CFLAGS} 'examples/example_tri.c' ${LIBS} -o "examples/example_tri_${PLATFORM}_${IMPL}.exe"
${CC} ${CFLAGS} 'examples/example_texcube.c' ${LIBS} -o "examples/example_texcube_${PLATFORM}_${IMPL}.exe"
