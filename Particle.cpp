
#include "Particle.h"
#include <stdlib.h>
#include <iostream>

namespace myparticleexplosion {

    Particle::Particle() {
        m_x = 2.0 * rand() / RAND_MAX - 1;
        m_y = 2.0 * rand() / RAND_MAX - 1;
    }

    Particle::~Particle() {

    }

    void Particle::update() {
        m_x += 0.01;
        m_y += 0.01;
    }
}
