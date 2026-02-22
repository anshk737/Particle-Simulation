#ifndef SIMULATION_H
#define SIMULATION_H

#include "particle.h"

using namespace std;

class Simulation {

    public:

        Simulation() {};

        float dotProduct(sf::Vector2f v1, sf::Vector2f v2);

        float dist(sf::Vector2f v);

        sf::Vector2f normalise(sf::Vector2f v);

        void calculateMomentum(Particle& obj1, Particle& obj2);

        void boundaryCheck(Particle& obj);

        void collide(Particle& obj1, Particle& obj2);

};

#endif