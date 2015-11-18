#include <SFML/Graphics.hpp>
#include "util.hpp"

#include "Ocean.hpp"
#include "Atmosphere.hpp"
#include "Organism.hpp"
#include "Bone.hpp"

using sf::Clock;
using sf::Mouse;
using sf::Vector2f;
using sf::RectangleShape;

sf::RenderWindow window(sf::VideoMode(), "Scubadarwin", sf::Style::Fullscreen);
const float WIDTH = window.getSize().x, HEIGHT = window.getSize().y;
const auto SCREEN_CENTER = Vector2f(WIDTH/2, HEIGHT/2);

std::set<PhysicsEntity*> entities;

Ocean* ocean;
Atmosphere* atmosphere;

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
    atmosphere->Entity::setPosition(Vector2f(0,0));
    atmosphere->setColor(Color::Cyan);
    
    Organism* parent = Organism::randomlyGenerateOrganism(5);

    for (int i = 0; i < 100; i++) {
        auto kid = parent->reproduce();
        kid->setPosition(Vector2f(sdu::rin(2000), sdu::rin(2000)));
        entities.insert(kid);
    }
    
}

Clock deltaTimeClock;

void applyZoneEffectsWhenZonesTouch(PhysicsEntity* entity)
{
    if (entity->touching(atmosphere)) atmosphere->affect(entity);
    if (entity->touching(ocean)) ocean->affect(entity);
}

void update()
{
    float dt = deltaTimeClock.restart().asSeconds();
    
    auto mpos = (Vector2f) Mouse::getPosition(window);
    
    auto mouseVector = mpos - SCREEN_CENTER;
    if (sdu::magnitude(mouseVector) < 100) mouseVector = Vector2f();
    
    for (auto entity : entities) {
        
        applyZoneEffectsWhenZonesTouch(entity);
        
        if (Mouse::isButtonPressed(Mouse::Button::Right))
            entity->applyForce((mpos - entity->getPosition())*5000.0f);
        
        if (entity->getPosition().y > HEIGHT * 2) entity->move(Vector2f(0, -HEIGHT*2));
        
        for (auto other : entities) {
            if (other == entity) continue;
            if (entity->touching(other)) {
                //entity->setColor(sf::Color::Yellow);
            }
        }
        
        entity->update(dt);
        
        entity->move(-mouseVector*dt);
        
    }
    
    ocean->move(-mouseVector*dt);
    atmosphere->move(-mouseVector*dt);

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
    
    draw(ocean);
    draw(atmosphere);
    
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