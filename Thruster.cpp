//
//  Thruster.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Thruster.hpp"

Thruster::Thruster(Organism* organism, bool randomlyGenerated) : Organ(organism)
{
    setDensity(4);
    
    if (!randomlyGenerated) return;
    
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setFillColor(Color(230, 180, 180));
        addShape(shape);
    }
    
    thrustVector = Vector2f(sdu::rsign(sdu::rin(100000)), sdu::rsign(sdu::rin(100000)));
    
    initializePosition();
}

Thruster::~Thruster() {}

void Thruster::update(float dt)
{
    Organ::update(dt);
    organism->applyForce(thrustVector);
    organism->setEnergy(organism->getEnergy() - 0.00000001 * sdu::magnitude(thrustVector));
}

ShapeEntity* Thruster::makeNewInstance() const
{
    // Todo: Maybe reconsider the clone() + makeNewInstance() setup.
    // Maybe call a special Organ clone() from the overridden one?
    // Also, see if we can refactor Organ constructors to reduce duplication.
    auto t = new Thruster;
    t->thrustVector = thrustVector;
    return t;
}