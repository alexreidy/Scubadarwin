//
//  Organ.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Organ_hpp
#define Organ_hpp

#include "PhysicsEntity.hpp"
#include "Organism.hpp"

class ImpulseReceiver{};

class Organism;

class Organ : public PhysicsEntity, ImpulseReceiver {
public:
    Organ(Organism* organism = nullptr);
    virtual ~Organ();
    
    virtual void update(float tpf) = 0;
    
protected:
    Organism* organism;
    
};

#endif /* Organ_hpp */