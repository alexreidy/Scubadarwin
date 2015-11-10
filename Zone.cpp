//
//  Zone.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Zone.hpp"

Zone::~Zone() {}

void Zone::update(float dt) {}

void Zone::affectAnyContainedEntitiesIn(const std::vector<PhysicsEntity*>& entities)
{
    for (auto entity : entities) {
        if (entity->touching(*this)) {
            affect(entity);
        }
    }
}