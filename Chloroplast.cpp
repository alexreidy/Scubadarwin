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
    
    initializePosition();
}

Chloroplast::~Chloroplast() {}

void Chloroplast::update(float dt)
{
    Organ::update(dt);
}

ShapeEntity* Chloroplast::makeNewInstance() const
{
    return new Chloroplast;
}