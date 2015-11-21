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

Bone::Bone(Organism* organism, bool randomlyGenerated) : Organ(organism)
{
    setDensity(2.0);
    
    if (!randomlyGenerated) return;
    
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setFillColor(Color(232,225,225));
        addShape(shape);
    }
    
    initializePosition();
}

Bone::~Bone() {}

void Bone::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Bone::makeNewInstance() const
{
    return new Bone;
}

void Bone::affect(SimEntity* entity)
{
    
}