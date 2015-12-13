#include <SFML/Graphics.hpp>
#include "util.hpp"

#include "Ocean.hpp"
#include "Atmosphere.hpp"

#include "Photon.hpp"

#include "Organism.hpp"
#include "Thruster.hpp"

using sf::Clock;
using sf::Mouse;
using sf::Vector2f;
using sf::RectangleShape;

sf::RenderWindow window(sf::VideoMode(), "Scubadarwin", sf::Style::Fullscreen);
const float SCREEN_WIDTH = window.getSize().x, SCREEN_HEIGHT = window.getSize().y;
const auto SCREEN_CENTER = Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

const float WORLD_WIDTH = SCREEN_WIDTH * 2;

Clock deltaTimeClock;

std::list<SimEntity*> entities, entitiesToDelete;

Ocean* ocean;
Atmosphere* atmosphere;

void spawn(int count)
{
    for (int i = 0; i < count; i++) {
        auto o = Organism::randomlyGenerateOrganism(5);
        o->setPosition(Vector2f(ocean->getPosition().x + sdu::rin(WORLD_WIDTH),
            ocean->getPosition().y + sdu::rin(SCREEN_HEIGHT)));
        entities.push_back(o);
    }
}

void init()
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    ocean = new Ocean;
    ocean->addShape(new RectangleShape(Vector2f(WORLD_WIDTH, SCREEN_HEIGHT*2)));
    ocean->setPosition(Vector2f(0, SCREEN_HEIGHT/2));
    ocean->setColor(Color(0,51,204));
    
    atmosphere = new Atmosphere;
    atmosphere->addShape(new RectangleShape(Vector2f(WORLD_WIDTH, SCREEN_HEIGHT/2)));
    atmosphere->setPosition(Vector2f(0,0));
    atmosphere->setColor(Color(0, 153, 255));
    
    entities.push_back(ocean);
    entities.push_back(atmosphere);
    
    spawn(50);
    
}

void update() {
    float dt = deltaTimeClock.restart().asSeconds();
    
    auto mpos = (Vector2f) Mouse::getPosition(window);
    
    auto mouseVector = mpos - SCREEN_CENTER;
    if (sdu::magnitude(mouseVector) < 100) mouseVector = Vector2f();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        spawn(5);
    }
    
    if (entities.size() < 500 && sdu::rin(1) > 0.8) {
        for (int i = 0; i < 5; i++) {
            auto photon = new Photon;
            photon->setPosition(Vector2f(
                atmosphere->getPosition().x + sdu::rin(WORLD_WIDTH),
                atmosphere->getPosition().y));
            entities.push_back(photon);
        }
    }
    
    if (sdu::rin(1) > 0.97) {
        spawn(1);
    }
    
    for (auto entity : entities) {
        if (Mouse::isButtonPressed(Mouse::Button::Right))
            entity->applyForce((mpos - entity->getPosition())*5000.0f);
        
        entity->affect(entities);
        entity->update(dt);
        
        for (auto p : entity->getProducts()) {
            entities.push_back(p);
        }
        
        if (entity->canBeDeleted()) {
            entitiesToDelete.push_back(entity);
            continue;
        }
        
        entity->move(-mouseVector*dt);
        
    }
    
    for (auto entity : entitiesToDelete) {
        entities.remove(entity);
        delete entity;
    }
    
    entitiesToDelete.clear();
    
}

void draw(const ShapeEntity* shapeEntity)
{
    for (auto& shape : shapeEntity->getShapes()) {
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