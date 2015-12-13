//
//  Photon.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 12/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Photon.hpp"

Photon::Photon()
{
    setLightEnergy(4000);
    auto shape = new CircleShape(6);
    shape->setFillColor(Color::Yellow);
    addShape(shape);
}

Photon::~Photon() {}

void Photon::update(float dt)
{
    setLightEnergy(getLightEnergy() - 300*dt);
    move(Vector2f(0, 150 * dt));
}

void Photon::affect(SimEntity* entity)
{
    
}

ShapeEntity* Photon::makeNewInstance() const
{
    return new Photon;
}

bool Photon::canBeDeleted() const
{
    return getLightEnergy() <= 0;
}

