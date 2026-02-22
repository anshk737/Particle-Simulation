#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;

class Particle {
    public:
        sf::CircleShape object;
        sf::Vector2f velocity;
        float mass;

        Particle(sf::Color col, float v1, float v2, float p1, float p2, float m);
};

#endif