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
const int N_ORGAN_TYPES = 2;

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
    getOrganGenerator<Thruster>()
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
        organism->addPhysicsEntity(organ);
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
}

Organism* Organism::reproduce()
{
    // TODO add chance of mutation arg?
    auto child = (Organism*) clone();
    //mutate
    return child;
}

void Organism::update(float dt)
{
    CompoundPhysicsEntity::update(dt);
}

void Organism::changeNutrients(float delta)
{
    nutrients += delta;
}

ShapeEntity* Organism::clone() const
{
    auto clone = new Organism;
    
    for (auto entity : getPhysicsEntities()) {
        clone->addPhysicsEntity((PhysicsEntity*) entity->clone());
    }
    
    return clone;
}
