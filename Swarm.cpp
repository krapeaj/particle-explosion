
#include "Swarm.h"

namespace myparticleexplosion {

    Swarm::Swarm() {
        m_particles = new Particle[Swarm::NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] m_particles;
    }

    void Swarm::update() {
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            m_particles[i].update();
        }
    }
}
