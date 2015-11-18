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
    if (!randomlyGenerated)
        return;
    for (int i = 0; i < 1; i++) {
        auto shape = new CircleShape(sdu::rin(20)+2);
        shape->setFillColor(Color(230, 180, 180));
        addShape(shape);
    }
    
    for (auto shape : organism->getShapes()) {
        setPosition(shape->getPosition() +
            Vector2f(sdu::rin(shape->getLocalBounds().width),
                     sdu::rin(shape->getLocalBounds().height)));
        if (sdu::rin(1) > 0.85)
            break;
    }

}

Thruster::~Thruster() {}

void Thruster::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Thruster::clone() const
{
    auto clone = new Thruster;
    
    for (auto shape : getShapes()) {
        auto cloneShape = new CircleShape(shape->getLocalBounds().width / 2);
        cloneShape->setPosition(shape->getPosition());
        cloneShape->setFillColor(shape->getFillColor());
        clone->addShape(cloneShape);
    }
    
    return clone;
}