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
    
    initializePosition();
}

Thruster::~Thruster() {}

void Thruster::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Thruster::makeNewInstance() const
{
    return new Thruster;
}