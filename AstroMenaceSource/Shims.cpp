#include <GL/GL.h>
#include <AL/al.h>
#include <SDL.h>

extern "C" {
    void glPushAttrib(GLbitfield) {
    }

    void glPopAttrib() {
    }

    const GLubyte* gluErrorString(GLenum error) {
        return reinterpret_cast<const GLubyte*>("");
    }

    void glLightf(
        GLenum light,
        GLenum pname,
        GLfloat param
    ) {
    }

    GLint gluBuild2DMipmaps(GLenum  target,  GLint  internalFormat,  GLsizei  width,  GLsizei  height,  GLenum  format,  GLenum  type,  const void *  data) {
        return 1;        
    }

    ALboolean alIsSource(ALuint sourceName) {
        return AL_FALSE;
    }

    void alSourceRewind(ALuint sourceName) {
    }

    int SDL_GetWMInfo(SDL_SysWMinfo* info) {
        return 0;
    }

    int SDL_GetGammaRamp(Uint16 *redtable, Uint16 *greentable, Uint16 *bluetable) {
        return -1;
    }

    int SDL_WaitEvent(SDL_Event *event) {
        return 0;
    }

    void SDL_Delay(Uint32) {
    }
}
