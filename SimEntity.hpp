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
    virtual ~SimEntity();
    
    virtual void affect(SimEntity* entity) = 0;

private:
    
};

#endif /* SimEntity_hpp */
