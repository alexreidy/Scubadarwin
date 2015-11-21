//
//  Environment.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/20/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Environment.hpp"

Environment::~Environment() {}

void Environment::update(float dt) {}

void Environment::affect(SimEntity* entity) {}

ShapeEntity* Environment::makeNewInstance() const
{
    return new Environment;
}