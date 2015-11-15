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
        //auto shape = new sf::RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setPosition(sdu::rin(75), sdu::rin(75));
        shape->setFillColor(Color(230, 180, 180));
        addShape(shape);
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
        cloneShape->setFillColor(Color(230, 180, 180));
        clone->addShape(cloneShape);
    }
    
    return clone;
}