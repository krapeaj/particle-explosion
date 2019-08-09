#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace myparticleexplosion;

int main() {
    const int COLOR_RANGE = 128;
    const double RED_COLOR_CHANGE_RATE = 0.0002;
    const double GREEN_COLOR_CHANGE_RATE = 0.0001;
    const double BLUE_COLOR_CHANGE_RATE = 0.0003;

    // seed rand
    srand(time(NULL));

    // initialize screen
    Screen screen;
    if (!screen.init()) {
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;
    unsigned char red, green, blue;
    int elapsed;
    // game loop
    while (true) {
        // update particles' color and positions
        Particle *particles = swarm.getParticles();
        swarm.update();
        elapsed = SDL_GetTicks();
        red = COLOR_RANGE * (1 + sin(elapsed * RED_COLOR_CHANGE_RATE));
        green = COLOR_RANGE * (1 + sin(elapsed * GREEN_COLOR_CHANGE_RATE));
        blue = COLOR_RANGE * (1 + sin(elapsed * BLUE_COLOR_CHANGE_RATE));
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = particles[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;
            screen.setPixel(x, y, red, green, blue);
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