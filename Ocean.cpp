//
//  Ocean.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Ocean.hpp"

Ocean::~Ocean() {}

Ocean::Ocean(std::vector<Shape*>* shapes)
{
    setShapes(shapes);
    setDensity(3);
}

ShapeEntity* Ocean::clone() const
{
    return new Ocean;
}