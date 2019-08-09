
#include "Swarm.h"

namespace myparticleexplosion {

    Swarm::Swarm() {
        m_particles = new Particle[Swarm::NPARTICLES];
        last_time = 0;
    }

    Swarm::~Swarm() {
        delete[] m_particles;
    }

    void Swarm::update(int elapsed) {
        int interval = elapsed - last_time;
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            m_particles[i].update(interval);
        }
        last_time = elapsed;
    }
}
