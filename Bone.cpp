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
    if (!randomlyGenerated)
        return;
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+5, sdu::rin(30)+5));
        shape->setFillColor(Color(232,225,225));
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

Bone::~Bone() {}

void Bone::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Bone::clone() const
{
    auto clone = new Bone;
    
    for (auto shape : getShapes()) {
        auto cloneShape = new RectangleShape(Vector2f(
            shape->getLocalBounds().width, shape->getLocalBounds().height));
        cloneShape->setPosition(shape->getPosition());
        cloneShape->setFillColor(shape->getFillColor());
        clone->addShape(cloneShape);
    }
    
    return clone;
}