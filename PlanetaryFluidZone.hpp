//
//  PlanetaryFluidZone.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef PlanetaryFluidZone_hpp
#define PlanetaryFluidZone_hpp

#include "GravityZone.hpp"

class PlanetaryFluidZone : public GravityZone {
public:
    PlanetaryFluidZone();
    
    virtual ~PlanetaryFluidZone();
    
    virtual void affect(SimEntity* entity) override;
    
protected:    
    virtual Vector2f calcDragActingOn(const PhysicsEntity* entity) const;
    
    
};

#endif /* PlanetaryFluidZone_hpp */