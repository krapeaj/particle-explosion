
#include "Particle.h"

#ifndef SDL_BASIC_SWARM_H
#define SDL_BASIC_SWARM_H

namespace myparticleexplosion {

    class Swarm {
    public:
        const static int NPARTICLES = 4000;

    private:
        Particle *m_particles;

    public:
        Swarm();

        virtual ~Swarm();

        Particle *getParticles() { return m_particles; };

        void update();
    };

#endif //SDL_BASIC_SWARM_H

}
