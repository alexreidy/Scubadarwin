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

typedef std::function<Organ*(Organism*)> OrganGeneratorFunction;

template <class OrganType>
OrganGeneratorFunction getOrganGenerator()
{
    return [](Organism* organism) -> Organ* {
        // where should we generate random organs and mutated organs? In constructors?
        
        return new OrganType(organism);
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
    for (int i = 0; i < 5; i++) {
        Organ* organ = makeRandomOrganForOrganism(this);
        addPhysicsEntity(organ);
    }
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
    return nullptr;
}

void Organism::update(float tpf)
{
    CompoundPhysicsEntity::update(tpf);
}

void Organism::changeNutrients(float delta)
{
    nutrients += delta;
}