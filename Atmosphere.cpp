//
//  Atmosphere.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Atmosphere.hpp"

Atmosphere::~Atmosphere() {}

Atmosphere::Atmosphere(std::vector<Shape*> shapes)
{
    setShapes(shapes);
    setDensity(0.001);
}