//
//  Organ.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Organ.hpp"

Organ::Organ(Organism* organism)
{
    this->organism = organism;
    setShapes(new std::vector<Shape*>);
}

Organ::~Organ() {}

void Organ::update(float tpf)
{
    PhysicsEntity::update(tpf);
}