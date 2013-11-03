import os

env = Environment(
    ENV=os.environ,
    EMHOME='/Users/chad/projects/emscripten',
    CC='$EMHOME/emcc',
    CXX='$EMHOME/em++',
    AR='$EMHOME/emar',
    RANLIB='$EMHOME/emranlib',
    OBJSUFFIX='.bc',
    LIBSUFFIX='.bc',
    CPPPATH=[
        '#/deps/libogg-1.3.1/include',
        '#/deps/libvorbis-1.3.3/include'],
    EMFLAGS=['-Wall', '-Wno-unused-variable', '-O0'])

Export('env')
SConscript(dirs=['.'], variant_dir='build', duplicate=0)

#env.Command(['clibs.bc'], [LIBOGG, LIBVORBIS], '$EMCC $EMFLAGS -o clibs.bc ')
#SOURCES=$(find AstroMenaceSource -iname '*.cpp')
#LIBOGG=$(find deps/libogg-1.3.1/src -iname '*.c')
#LIBVORBIS="deps/libvorbis-1.3.3/lib/vorbisfile.c deps/libvorbis-1.3.3/lib/info.c deps/libvorbis-1.3.3/lib/synthesis.c deps/libvorbis-1.3.3/lib/block.c deps/libvorbis-1.3.3/lib/codebook.c deps/libvorbis-1.3.3/lib/sharedbook.c"
#mdct.c smallft.c block.c envelope.c window.c lsp.c \
#			lpc.c analysis.c synthesis.c psy.c info.c \
#			floor1.c floor0.c\
#			res0.c mapping0.c registry.c codebook.c sharedbook.c\
#			lookup.c bitrate.c
#$EMCC -Wall -Wno-unused-variable -O0 -o clibs.bc -Ideps/libvorbis-1.3.3/include -Ideps/libogg-1.3.1/include  $LIBOGG $LIBVORBIS
#
#$EMPP -s LEGACY_GL_EMULATION=1 -s SAFE_DYNCALLS=1 -s ERROR_ON_UNDEFINED_SYMBOLS=1 -Wall -Wno-unused-variable -O0 -I$EMHOME/tests/freetype/include -I$EMHOME/tests/freealut/include -Ideps/libvorbis-1.3.3/include -Ideps/libogg-1.3.1/include -o AstroMenace.html $SOURCES clibs.bc
