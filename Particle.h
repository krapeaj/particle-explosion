
#ifndef SDL_BASIC_PARTICLE_H
#define SDL_BASIC_PARTICLE_H

namespace myparticleexplosion {

    class Particle {
    public:
        double m_x;
        double m_y;

    public:
        Particle();

        virtual ~Particle();

        void update();
    };


#endif //SDL_BASIC_PARTICLE_H

} /* namespace myparticleexplosion */
