//
//  SimEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/17/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "SimEntity.hpp"

SimEntity::SimEntity()
{

}

SimEntity::~SimEntity() {}

bool SimEntity::canBeDeleted() const
{
    return false;
}

std::vector<SimEntity*> SimEntity::getProducts()
{
    auto ret = products;
    products.clear();
    return ret;
}

void SimEntity::affect(const std::list<SimEntity*>& entities)
{
    for (auto entity : entities) {
        if (entity == this) continue;
        if (touching(entity)) {
            affect(entity);
        }
    }
}

const SimEntity* SimEntity::getID() const
{
    return this;
}

float SimEntity::getEnergy() const
{
    return energy;
}

void SimEntity::setEnergy(float e)
{
    if (e < 0) e = 0;
    energy = e;
}

float SimEntity::getEnergyUsed()
{
    auto eu = energyUsed;
    energyUsed = 0;
    return eu;
}

void SimEntity::setEnergyUsed(float e)
{
    energyUsed = e;
}

float SimEntity::getLightEnergy() const
{
    return lightEnergy;
}

void SimEntity::setLightEnergy(float e)
{
    lightEnergy = e;
}