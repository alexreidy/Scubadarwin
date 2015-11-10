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
    
    virtual void affect(PhysicsEntity* entity) override;
    
    void setDensity(float density);
    
    float getDensity() const;
    
protected:    
    virtual Vector2f calcDragActingOn(PhysicsEntity* entity) const;
    
private:
    float density = 1;
    
    
};

#endif /* PlanetaryFluidZone_hpp */