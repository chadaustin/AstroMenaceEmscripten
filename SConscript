import os

Import('*')

LIBOGG = env.Glob('deps/libogg-1.3.1/src/*.c')

env.Library(['ogg'], LIBOGG)

LIBVORBIS = [os.path.join('deps', 'libvorbis-1.3.3', 'lib', x) for x in env.Split("""
    mdct.c smallft.c block.c envelope.c window.c lsp.c 
    lpc.c analysis.c synthesis.c psy.c info.c
    floor1.c floor0.c\
    res0.c mapping0.c registry.c codebook.c sharedbook.c\
    lookup.c bitrate.c vorbisfile.c""")]

env.Library(['vorbis'], LIBVORBIS)
