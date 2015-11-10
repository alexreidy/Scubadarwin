//
//  Bone.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Bone.hpp"

using sf::RectangleShape;
using sf::Color;

Bone::Bone(Organism* organism) : Organ(organism)
{
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setPosition(sdu::rin(30), sdu::rin(30));
        shape->setFillColor(Color(232,225,225));
        addShape(shape);
    }
    setDensity(0.95);
}

Bone::~Bone() {}

void Bone::update(float dt)
{
    Organ::update(dt);
}