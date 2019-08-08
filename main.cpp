#include <iostream>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace myparticleexplosion;

int main() {
    const int COLOR_RANGE = 128;
    const double RED_COLOR_CHANGE_RATE = 0.0006;
    const double GREEN_COLOR_CHANGE_RATE = 0.002;
    const double BLUE_COLOR_CHANGE_RATE = 0.001;

    Screen screen;
    if (!screen.init()) {
        cout << "Error initializing SDL." << endl;
    }

    // game loop
    unsigned char red, green, blue;
    while (true) {
        // update particles
        int elapsed = SDL_GetTicks();
        red = COLOR_RANGE * (1 + cos(elapsed * RED_COLOR_CHANGE_RATE));
        green = COLOR_RANGE * (1 + sin(elapsed * GREEN_COLOR_CHANGE_RATE));
        green = COLOR_RANGE * (1 + sin(elapsed * BLUE_COLOR_CHANGE_RATE));


        // draw particles
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        screen.update();

        // check for messages/events
        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();
    return 0;
}