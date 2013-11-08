import os

env = Environment(
    ENV=os.environ,
    EMHOME='/Users/chad/projects/emscripten',
    CC='$EMHOME/emcc',
    CXX='$EMHOME/em++',
    AR='/opt/local/bin/llvm-link-mp-3.2',
    ARCOM='$AR -o $TARGET $SOURCES',
    RANLIB='$EMHOME/emranlib',
    OBJSUFFIX='.bc',
    LIBSUFFIX='.bc',
    PROGSUFFIX='.html',
    CPPDEFINES=[
        'HAVE_STDIO_H',
        'HAVE_STDINT_H',
        'HAVE_STAT',
        'HAVE_USLEEP',
        'HAVE_UNISTD_H',
        'FT2_BUILD_LIBRARY',
    ],
    CPPPATH=[
        '#/deps/regal/src/glu/include',
        '#/deps/libogg-1.3.1/include',
        '#/deps/libvorbis-1.3.3/include',
        '$EMHOME/tests/freetype/include',
        '$EMHOME/tests/freealut/include' ],
    CCFLAGS=[
        '-Wall',
        '-Wno-unused-variable',
        '-Wno-warn-absolute-paths',
        '-Wno-unused-function',
        '-Wno-overloaded-virtual',
        '-O2',
        '-g'],
    LINKFLAGS=[
        '-O1',
        '-g3',
        '-s', 'LEGACY_GL_EMULATION=1',
        '-s', 'ASM_JS=0',
        '-s', 'TOTAL_MEMORY=209715200',
        '-s', 'SAFE_DYNCALLS=1',
        '-s', 'ERROR_ON_UNDEFINED_SYMBOLS=1' ])

Export('env')
SConscript(dirs=['.'], variant_dir='build', duplicate=0)

