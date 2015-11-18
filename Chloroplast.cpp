//
//  Chloroplast.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/15/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Chloroplast.hpp"

Chloroplast::Chloroplast(Organism* parent, bool randomlyGenerated) : Organ(parent)
{
    setDensity(3.5);
    if (!randomlyGenerated) return;
    
    for (int i = 0; i < 1; i++) {
        auto shape = new RectangleShape(Vector2f(sdu::rin(30)+3, sdu::rin(30)+3));
        shape->setFillColor(Color(20, 255, 140));
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

Chloroplast::~Chloroplast() {}

void Chloroplast::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Chloroplast::clone() const
{
    auto clone = new Chloroplast;
    
    for (auto shape : getShapes()) {
        auto cloneShape = new RectangleShape(Vector2f(shape->getLocalBounds().width, shape->getLocalBounds().height));
        cloneShape->setPosition(shape->getPosition());
        cloneShape->setFillColor(shape->getFillColor());
        clone->addShape(cloneShape);
    }
    
    return clone;
}