
#include "Particle.h"

#ifndef SDL_BASIC_SWARM_H
#define SDL_BASIC_SWARM_H

namespace myparticleexplosion {

    class Swarm {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle *m_particles;
        int last_time;

    public:
        Swarm();

        virtual ~Swarm();

        Particle *getParticles() { return m_particles; };

        void update(int elapsed);
    };

#endif //SDL_BASIC_SWARM_H

}
