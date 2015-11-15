//
//  Atmosphere.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Atmosphere.hpp"

Atmosphere::~Atmosphere() {}

Atmosphere::Atmosphere()
{
    setDensity(0.2);
}

ShapeEntity* Atmosphere::clone() const
{
    return new Atmosphere;
}