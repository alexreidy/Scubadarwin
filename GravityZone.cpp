//
//  GravityZone.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "GravityZone.hpp"

GravityZone::~GravityZone() {}

void GravityZone::setGravityAcceleration(const Vector2f& g)
{
    this->g = g;
}

Vector2f GravityZone::getGravityAcceleration() const
{
    return g;
}

void GravityZone::affect(SimEntity* entity)
{
    entity->applyForce(entity->getMass() * g);
}