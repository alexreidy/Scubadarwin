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
        for (auto shp : organism->getShapes()) {
            if (shp == nullptr) {
                std::cout<<"nullalready!!!";
            }
        }
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
    // TODO add chance of mutation arg?
    auto child = static_cast<Organism*>(clone());
    //mutate
    
    return child;
}

void Organism::update(float dt)
{
    CompoundSimEntity::update(dt);
    changeHp(-0.00001*getMass());
}

void Organism::changeNutrients(float delta)
{
    nutrients += delta;
}

ShapeEntity* Organism::clone() const
{
    auto clone = new Organism;
    
    for (auto entity : getConstituentEntities()) {
        clone->addEntity(static_cast<SimEntity*>(entity->clone()));
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