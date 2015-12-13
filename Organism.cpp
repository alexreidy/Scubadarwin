//
//  Organism.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Organism.hpp"

#include "Bone.hpp"
#include "Thruster.hpp"
#include "Chloroplast.hpp"
#include "Mouth.hpp"

const int N_ORGAN_TYPES = 4;

// Consider using OrganGenerator(Factory) classes, particularly if they're faster

typedef std::function<Organ*(Organism*)> OrganGeneratorFunction;

template <class OrganType>
OrganGeneratorFunction getOrganGenerator()
{
    return [](Organism* organism) -> Organ* {
        return new OrganType(organism, true);
    };
}

OrganGeneratorFunction organGenerators[N_ORGAN_TYPES] = {
    getOrganGenerator<Bone>(),
    getOrganGenerator<Thruster>(),
    getOrganGenerator<Chloroplast>(),
    getOrganGenerator<Mouth>()
};

Organ* makeRandomOrganForOrganism(Organism* organism)
{
    int index = (int) floorf(sdu::rin(N_ORGAN_TYPES));
    return organGenerators[index](organism);
}

Organism::Organism()
{
    
}

Organism* Organism::randomlyGenerateOrganism(int organCount)
{
    auto organism = new Organism;
    
    for (int i = 0; i < organCount; i++) {
        Organ* organ = makeRandomOrganForOrganism(organism);
        organism->addEntity(organ);
    }
    
    organism->setEnergy(organism->getMass());
    
    return organism;
}

Organism::~Organism()
{
    
}

bool Organism::isAlive() const
{
    return getEnergy() > 0 && alive;
}

void Organism::die()
{
    alive = false;
}

Organism* Organism::reproduce()
{
    // TODO add "propensity to mutate" arg?
    auto child = static_cast<Organism*>(clone());
    
    if (sdu::rin(1) > 0.8) return child;
    
    std::list<SimEntity*> organsToRemove;
    
    for (auto organ : child->getConstituentEntities()) {
        if (sdu::rin(1) > 0.93) {
            organsToRemove.push_back(organ);
        }
        if (sdu::rin(1) > 0.95) {
            child->addEntity(makeRandomOrganForOrganism(child));
        }
        // maybe have ShapeEntity->mutate(...)?
    }
    
    if (organsToRemove.size() != getConstituentEntities().size()) {
        for (auto organ : organsToRemove) {
            child->removeEntity(organ);
        }
    }
    
    child->setEnergy(child->getMass());
    
    child->setPosition(getPosition() +
        Vector2f( sdu::rsign(sdu::rin(100)), sdu::rsign(sdu::rin(100)) ));
    
    return child;
}

void Organism::update(float dt)
{
    for (auto organ : getConstituentEntities()) {
        organ->update(dt);
    }
    
    PhysicsEntity::update(dt);
    
    float energyUsed = 0;
    if (getEnergy() >= getMass() * 2) {
        products.push_back(this->reproduce());
        setEnergy(getEnergy() - getMass());
        energyUsed += getMass();
    }
    
    energyUsed += 0.02*dt*(1000000/getMass());
    
    setEnergy(getEnergy() - energyUsed);
}

ShapeEntity* Organism::clone() const
{
    auto clone = new Organism;
    //clone->setPosition(this->getPosition());
    
    for (auto entity : getConstituentEntities()) {
        auto organ = static_cast<Organ*>(entity->clone());
        organ->setParentOrganism(clone);
        clone->addEntity(organ);
    }
    
    return clone;
}

ShapeEntity* Organism::makeNewInstance() const
{
    return new Organism;
}

void Organism::affect(SimEntity* entity)
{
    
}

bool Organism::canBeDeleted() const
{
    return !isAlive() || getConstituentEntities().size() == 0;
}