//
//  Atmosphere.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Atmosphere_hpp
#define Atmosphere_hpp

#include "PlanetaryFluidZone.hpp"

class Atmosphere : public PlanetaryFluidZone {
public:
    Atmosphere(std::vector<Shape*> shapes);
    
    virtual ~Atmosphere();
    
};

#endif /* Atmosphere_hpp */
