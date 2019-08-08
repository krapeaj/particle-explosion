
#ifndef SDL_BASIC_SCREEN_H
#define SDL_BASIC_SCREEN_H

#include <SDL.h>

namespace myparticleexplosion {

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;

public:
    Screen();
    bool init();
    bool processEvents();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void close();
};

} /* namespace myparticleexplosion */

#endif //SDL_BASIC_SCREEN_H
