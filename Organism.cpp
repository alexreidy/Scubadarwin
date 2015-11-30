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
const int N_ORGAN_TYPES = 3;

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
    getOrganGenerator<Chloroplast>()
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
    
    return organism;
}

Organism::~Organism()
{
    
}

bool Organism::isAlive() const
{
    return hp > 0;
}

void Organism::die()
{
    hp = 0;
    // delete this;
}

void Organism::changeHp(float change)
{
    hp += change;
}

Organism* Organism::reproduce()
{
    // TODO add "propensity to mutate" arg?
    auto child = static_cast<Organism*>(clone());
    
    std::list<SimEntity*> organsToRemove;
    
    // not sure exactly what's going on during iteration; will concurrent modification be an issue?
    for (auto organ : child->getConstituentEntities()) {
        if (sdu::rin(1) > 0.93) {
            organsToRemove.push_back(organ);
        }
        if (sdu::rin(1) > 0.95) {
            child->addEntity(makeRandomOrganForOrganism(child));
        }
        // maybe have ShapeEntity->mutate(...)?
    }
    
    for (auto organ : organsToRemove) {
        child->removeEntity(organ);
    }
    
    return child;
}

void Organism::update(float dt)
{
    CompoundSimEntity::update(dt);
    changeHp(-0.0001*getMass());
    if (hp <= 0) {
        products.push_back(this->reproduce());
    }
}

void Organism::changeNutrients(float delta)
{
    nutrients += delta;
}

ShapeEntity* Organism::clone() const
{
    auto clone = new Organism;
    clone->setPosition(this->getPosition());
    
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

void Organism::affect(SimEntity* entity) { entity->applyForce(sf::Vector2f(400000, 400000)); }

bool Organism::canBeDeleted() const
{
    return !isAlive();
}