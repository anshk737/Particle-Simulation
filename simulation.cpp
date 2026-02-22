#include "simulation.h"

float Simulation::dotProduct(sf::Vector2f v1, sf::Vector2f v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

float Simulation::dist(sf::Vector2f v) {
    return sqrt(v.x*v.x + v.y*v.y);
} 

sf::Vector2f Simulation::normalise(sf::Vector2f v) {
    float d = dist(v);
    v /= d;
    return v;
}

void Simulation::calculateMomentum(Particle& obj1, Particle& obj2) {
    sf::Vector2f v1 = obj1.velocity;
    sf::Vector2f v2 = obj2.velocity;
    sf::Vector2f p1 = obj1.object.getPosition();
    sf::Vector2f p2 = obj2.object.getPosition();

    sf::Vector2f posDiff = p1 - p2;
    sf::Vector2f velDiff = v1 - v2;

    float c = (2/(obj1.mass + obj2.mass))*(dotProduct(velDiff, posDiff)/dotProduct(posDiff, posDiff));

    obj1.velocity -= c*obj1.mass*posDiff;
    obj2.velocity += c*obj2.mass*posDiff;
}

void Simulation::boundaryCheck(Particle& obj) {
    sf::Vector2f pos = obj.object.getPosition();
    float r = obj.object.getRadius();
    if (pos.x - r < 0) {
        obj.velocity.x = -obj.velocity.x;
        pos.x = r;
        obj.object.setPosition(pos);
    } else if (pos.x + r > 800) {
        obj.velocity.x = -obj.velocity.x;
        pos.x = 800 - r;
        obj.object.setPosition(pos);
    }

    if (pos.y - r < 0) {
        obj.velocity.y = -obj.velocity.y;
        pos.y = r;
        obj.object.setPosition(pos);
    } else if (pos.y + r > 600) {
        obj.velocity.y = -obj.velocity.y;
        pos.y = 600 - r;
        obj.object.setPosition(pos);
    }

}

void Simulation::collide(Particle& obj1, Particle& obj2) {

    sf::Vector2f pos = obj1.object.getPosition();
    sf::Vector2f pos2 = obj2.object.getPosition();

    float r = obj1.object.getRadius();

    float d = dist(pos - pos2);

    if (d < 2*r) {
        float dx = r - d/2;
        pos -= normalise(obj1.velocity)*dx;
        pos2 -= normalise(obj2.velocity)*dx;
        obj1.object.setPosition(pos);
        obj2.object.setPosition(pos2);
        calculateMomentum(obj1, obj2);
    }

}
