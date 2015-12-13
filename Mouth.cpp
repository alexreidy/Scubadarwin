//
//  Mouth.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 12/7/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Mouth.hpp"

Mouth::Mouth(Organism* organism, bool randomlyGenerated) : Organ(organism)
{
    setDensity(3.5);
    
    if (!randomlyGenerated) return;
    
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setFillColor(Color::Red);
        addShape(shape);
    }
    
    initializePosition();
}

Mouth::~Mouth() {}

void Mouth::update(float dt)
{
    Organ::update(dt);
    organism->setEnergy(organism->getEnergy() - getVolume()*dt);
}

ShapeEntity* Mouth::makeNewInstance() const
{
    return new Mouth;
}

void Mouth::affect(SimEntity* entity)
{
    if (entity->getID() == getID())
        return;
    
    float energyConsumed = 10000;
    
    if (entity->getEnergy() >= energyConsumed) {
        entity->setEnergy(entity->getEnergy() - energyConsumed);
        organism->setEnergy(organism->getEnergy() + energyConsumed);
    } else {
        organism->setEnergy(organism->getEnergy() + entity->getEnergy());
        entity->setEnergy(0);
    }
    //entity->setColor(sf::Color::White);
}