#include "Screen.h"
#include <iostream>

namespace myparticleexplosion {

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL) {
}

bool Screen::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!m_window) {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!m_texture) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
}

bool Screen::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    Uint32 color = 0;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::boxBlur() {
    Uint32 *tmp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = tmp;

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {

            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int current_x = x + col;
                    int current_y = y + row;

                    if (current_x >= 0 && current_x < SCREEN_WIDTH && current_y >= 0 && current_y < SCREEN_HEIGHT) {
                        Uint32 color = m_buffer2[current_y * SCREEN_WIDTH + current_x];
                        Uint8 red = (color & 0xFF000000) >> 24;
                        Uint8 green = (color & 0x00FF0000) >> 16;
                        Uint8 blue = (color & 0x0000FF00) >> 8;

                        red_total += red;
                        green_total += green;
                        blue_total += blue;
                    }
                }
            }
            // take average of surrounding
            Uint8 red = red_total / 9;
            Uint8 green = green_total / 9;
            Uint8 blue = blue_total / 9;

            setPixel(x, y, red, green, blue);
        }
    }
}

void Screen::close() {
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
}
