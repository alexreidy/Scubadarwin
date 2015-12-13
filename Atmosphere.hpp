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
    Atmosphere();
    
    virtual ~Atmosphere();
    
    virtual ShapeEntity* makeNewInstance() const override;
    
    virtual void affect(SimEntity* entity) override;
    
};

#endif /* Atmosphere_hpp */
