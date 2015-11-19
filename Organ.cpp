//
//  Organ.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Organ.hpp"

Organ::Organ(Organism* organism)
{
    this->organism = organism;
}

Organ::~Organ() {}

void Organ::update(float dt)
{
    SimEntity::update(dt);
}

void Organ::initializePosition()
{
    if (organism == nullptr) return;
    
    for (auto shape : organism->getShapes()) {
        setPosition(shape->getPosition() +
            Vector2f(sdu::rin(shape->getLocalBounds().width),
                     sdu::rin(shape->getLocalBounds().height)));
        
        if (sdu::rin(1) > 0.85) break;
    }
}

void Organ::affect(SimEntity* entity) {}