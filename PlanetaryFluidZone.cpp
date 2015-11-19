//
//  PlanetaryFluidZone.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "PlanetaryFluidZone.hpp"

PlanetaryFluidZone::~PlanetaryFluidZone() {}

PlanetaryFluidZone::PlanetaryFluidZone()
{
    setGravityAcceleration(Vector2f(0, 280));
}

void PlanetaryFluidZone::setDensity(float density)
{
    this->density = density;
}

float PlanetaryFluidZone::getDensity() const
{
    return density;
}

inline float drag(float fluidDensity, float objVelocity, float objArea)
{
    const auto drag = 0.5 * fluidDensity * pow(objVelocity, 2) * objArea * 0.02;
    if (objVelocity > 0) return -drag;
    return drag;
}

Vector2f PlanetaryFluidZone::calcDragActingOn(const PhysicsEntity* entity) const
{
    const auto velocity = entity->getVelocity();
    const auto area = entity->getVolume() / 2;
    const auto fluidDensity = getDensity();
    return Vector2f(
        drag(fluidDensity, velocity.x, area),
        drag(fluidDensity, velocity.y, area)
    );
}

void PlanetaryFluidZone::affect(SimEntity* entity)
{
    GravityZone::affect(entity);
    Vector2f buoyancy = (entity->getVolume() * density) * getGravityAcceleration();
    entity->applyForce(calcDragActingOn(entity) - buoyancy);
}