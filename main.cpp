#include <SFML/Graphics.hpp>
#include "util.hpp"

#include "Ocean.hpp"
#include "Atmosphere.hpp"
#include "Environment.hpp"

#include "Organism.hpp"
#include "Thruster.hpp"

using sf::Clock;
using sf::Mouse;
using sf::Vector2f;
using sf::RectangleShape;

sf::RenderWindow window(sf::VideoMode(), "Scubadarwin", sf::Style::Fullscreen);
const float WIDTH = window.getSize().x, HEIGHT = window.getSize().y;
const auto SCREEN_CENTER = Vector2f(WIDTH/2, HEIGHT/2);

std::list<CompoundSimEntity*> entities;

Ocean* ocean;
Atmosphere* atmosphere;

Environment* environment;

void init()
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    ocean = new Ocean;
    ocean->addShape(new RectangleShape(Vector2f(WIDTH*20, HEIGHT*20)));
    ocean->setPosition(Vector2f(0, HEIGHT/2));
    ocean->setColor(Color::Blue);
    
    atmosphere = new Atmosphere;
    atmosphere->addShape(new RectangleShape(Vector2f(WIDTH*20, HEIGHT/2)));
    atmosphere->setPosition(Vector2f(0,0));
    atmosphere->setColor(Color::Cyan);
    
    environment = new Environment;
    environment->addEntity(ocean);
    environment->addEntity(atmosphere);
    
    entities.push_back(environment);
    
    for (int i = 0; i < 1; i++) {
        auto kid = Organism::randomlyGenerateOrganism(7);
        kid->setPosition(Vector2f(sdu::rin(2000), sdu::rin(2000)));
        entities.push_back(kid);
    }
}

Clock deltaTimeClock;

std::list<CompoundSimEntity*> entitiesToDelete;

void update()
{
    float dt = deltaTimeClock.restart().asSeconds();
    
    auto mpos = (Vector2f) Mouse::getPosition(window);
    
    auto mouseVector = mpos - SCREEN_CENTER;
    if (sdu::magnitude(mouseVector) < 100) mouseVector = Vector2f();
    
    for (auto entity : entities) {
        for (auto constituent : entity->getConstituentEntities()) {
            for (auto e : entities) {
                if (e == entity) continue;
                
                for (auto otherConstituent : e->getConstituentEntities()) {
                    if (constituent->touching(otherConstituent)) {
                        constituent->affect(otherConstituent);
                    }
                }
            }
            
            constituent->update(dt);
        }
    }
    
    for (auto entity : entities) {
        if (Mouse::isButtonPressed(Mouse::Button::Right))
            entity->applyForce((mpos - entity->getPosition())*5000.0f);
        
        entity->update(dt);
        
        entity->move(-mouseVector*dt);
        
        if (entity->canBeDeleted())
            entitiesToDelete.push_back(entity);
        
        for (auto p : entity->getProducts()) {
            entities.push_back(p);
        }
    }
    
    for (auto entity : entitiesToDelete) {
        entities.remove(entity);
        std::cout << "d ";
        delete entity;
    }
    
    entitiesToDelete.clear();

}

void draw(const ShapeEntity* shapeEntity)
{
    for (auto shape : shapeEntity->getShapes()) {
        window.draw(*shape);
    }
}

void render()
{
    window.clear();
    
    for (auto entity : entities) draw(entity);
    
    window.display();
}

int main(int argc, char** argv)
{
    init();
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
                window.close();
            break;
        }
        
        update();
        render();
        
    }

    return EXIT_SUCCESS;
}