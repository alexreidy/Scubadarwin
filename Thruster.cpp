//
//  Thruster.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Thruster.hpp"

Thruster::Thruster(Organism* organism) : Organ(organism)
{
    for (int i = 0; i < 1; i++) {
        auto shape = new CircleShape(sdu::rin(30)+5);
        shape->setPosition(sdu::rin(30), sdu::rin(30));
        shape->setFillColor(Color(230, 220, 100));
        addShape(shape);
    }
    setDensity(1.2);
}

Thruster::~Thruster() {}

void Thruster::update(float dt)
{
    Organ::update(dt);
}