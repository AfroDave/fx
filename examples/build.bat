@ECHO OFF

set CC=cl
set CFLAGS=-nologo -FC -MTd -W4 -Zi -Zo -Od -Iexamples

if "%1" == "gl45" (
    set IMPL="gl45"
    set CFLAGS=%CFLAGS% -DFX_GL45_IMPL
)

if "%1" == "gl33" (
    set IMPL="gl33"
    set CFLAGS=%CFLAGS% -DFX_GL33_IMPL
)

set LIBS=kernel32.lib glfw3.lib gdi32.lib

%CC% %CFLAGS% "examples\example_tri.c" -link %LIBS% -out:"examples\example_tri_%PLATFORM%_%IMPL%.exe"
REM %CC% %CFLAGS% "examples\example_texcube.c" -link %LIBS% -out:"examples\example_texcube_%PLATFORM%_%IMPL%.exe"
