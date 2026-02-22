#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "particle.h"
#include "simulation.h"

int main(void) {

    Simulation SIM;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");
    window.setPosition(sf::Vector2i(1920/2 - window.getSize().x/2, 1080/2 - window.getSize().y/2));

    sf::Clock clock;

    std::vector<Particle> objs;

    srand(time(0));

    float avg = 0;

    for (int i = 0; i < 10; ++i) {
        objs.push_back(Particle(sf::Color::Red, 10*(rand()%10+5), 10*(rand()%10+10), std::max(100, std::min(rand()%800, 700)), std::max(100, std::min(rand()%600, 500)), 10)); //rand()%50+5
        avg += SIM.dist(objs.back().velocity);
    }

    std::cout << avg/500.0f << std::endl;

    float dt = 0;

    while (window.isOpen()) {    
        
        sf::Time deltaT = clock.restart();
        
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (int i = 0; i < objs.size(); ++i) {
            SIM.boundaryCheck(objs[i]);
        }

        for (int i = 0; i < objs.size(); ++i) {
            for (int j = i+1; j < objs.size(); ++j) {
                SIM.collide(objs[i], objs[j]);
            }
        }

        window.clear();

        dt = deltaT.asSeconds();

        for (int i = 0; i < objs.size(); ++i) {
            objs[i].object.setPosition(objs[i].object.getPosition() + objs[i].velocity*dt);
        }

        for (int i = 0; i < objs.size(); ++i) {
            window.draw(objs[i].object);
        }
    
        window.display();
        
    }

    return 0;
}
