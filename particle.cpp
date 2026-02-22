#include "particle.h"

Particle::Particle(sf::Color col, float v1, float v2, float p1, float p2, float m) {
    object.setFillColor(col);
    object.setPosition(sf::Vector2f(p1, p2));
    mass = m;
    velocity = sf::Vector2f(v1, v2);
    float r = 20.0f;
    object.setRadius(r);
    object.setOrigin(r, r);
}