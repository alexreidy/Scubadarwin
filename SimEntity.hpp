//
//  SimEntity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/17/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef SimEntity_hpp
#define SimEntity_hpp

#include "PhysicsEntity.hpp"

class SimEntity : public PhysicsEntity {
public:
    SimEntity();
    
    virtual ~SimEntity();
    
    virtual void affect(SimEntity* entity) = 0;
    
    virtual void affect(const std::list<SimEntity*>& entities);
    
    virtual bool canBeDeleted() const;
    
    virtual std::vector<SimEntity*> getProducts();
    
    virtual const SimEntity* getID() const;
    
    virtual float getEnergy() const;
    
    virtual void setEnergy(float e);
    
    float getEnergyUsed();
    
    void setEnergyUsed(float e);
    
    float getLightEnergy() const;
    
    void setLightEnergy(float e);
        
protected:    
    std::vector<SimEntity*> products;
    
private:
    float energy = 0;
    
    float energyUsed = 0;
    
    float lightEnergy = 0;
    
};

#endif /* SimEntity_hpp */