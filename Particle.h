
#ifndef SDL_BASIC_PARTICLE_H
#define SDL_BASIC_PARTICLE_H

namespace myparticleexplosion {

    class Particle {
    private:
        double m_speed;
        double m_direction;

    public:
        double m_x;
        double m_y;

    private:
        void init();

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
    };


#endif //SDL_BASIC_PARTICLE_H

} /* namespace myparticleexplosion */
