#include <SFML/Graphics.hpp>
#include "util.hpp"

#include "Bone.hpp"
#include "Ocean.hpp"
#include "Atmosphere.hpp"

using sf::Clock;
using sf::Mouse;
using sf::Vector2f;
using sf::RectangleShape;

sf::RenderWindow window(sf::VideoMode(), "Scubadarwin", sf::Style::Fullscreen);
const float WIDTH = window.getSize().x, HEIGHT = window.getSize().y;
const auto SCREEN_CENTER = Vector2f(WIDTH/2, HEIGHT/2);

std::vector<PhysicsEntity*> entities;

Ocean* ocean;
Atmosphere* atmosphere;

void init()
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    std::vector<Shape*> oceanShape;
    oceanShape.push_back(new RectangleShape(Vector2f(WIDTH, HEIGHT)));
    ocean = new Ocean(oceanShape);
    ocean->setPosition(Vector2f(0, HEIGHT/2));
    ocean->setColor(Color::Blue);
    
    std::vector<Shape*> atmosphereShapes;
    atmosphereShapes.push_back(new RectangleShape(Vector2f(WIDTH, HEIGHT/2)));
    atmosphere = new Atmosphere(atmosphereShapes);
    atmosphere->Entity::setPosition(Vector2f(0,0));
    atmosphere->setColor(Color::Cyan);

    for (int i = 0; i < 25; i++) {
        
        auto e = new Organism;
        //e->addPhysicsEntity(new Bone(nullptr));
        e->setPosition(Vector2f(sdu::rin(2000), sdu::rin(2000)));
        entities.push_back(e);
        
        /*
        auto b = new Bone(nullptr);
        b->setPosition(sf::Vector2f(sdu::rin(2000), sdu::rin(2000)));
        entities.push_back(b);*/
    }
}

Clock deltaTimeClock;

void draw(const ShapeEntity* shapeEntity);

void update()
{
    float dt = deltaTimeClock.restart().asSeconds();
    
    auto mpos = (Vector2f) Mouse::getPosition(window);
    
    Vector2f viewOffset;
    
    auto mouseVector = mpos - SCREEN_CENTER;
    if (sdu::magnitude(mouseVector) < 100) mouseVector = Vector2f();
    
    for (auto entity : entities) {
        //auto norm = sdu::norm(mpos - entity->getPosition());
        //entity->applyForce(norm * 50000.0f);
        
        ocean->affectAnyContainedEntitiesIn(entities);
        atmosphere->affectAnyContainedEntitiesIn(entities); // todo: make something that does this in O(N) instead of O(2N)..
        
        if (entity->getPosition().y > HEIGHT * 2) entity->move(Vector2f(0, -HEIGHT*2));
        
        auto v = sdu::magnitude(entity->getVelocity());
        
        for (auto other : entities) {
            if (other == entity) continue;
            if (entity->touching(*other)) {
                entity->setColor(sf::Color::Yellow);
            }
        }
        
        //ocean->setPosition(mpos);
        
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
    
    for (auto entity : entities) {
        draw(entity);
    }
    
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