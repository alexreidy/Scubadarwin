//
//  PhysicsMedium.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/7/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef PhysicsMedium_hpp
#define PhysicsMedium_hpp

#include "ShapeEntity.hpp"
#include "PhysicsEntity.hpp"

class PhysicsMedium : public ShapeEntity {
public:
    virtual ~PhysicsMedium();
    
    virtual void affect(PhysicsEntity* entity) = 0;
    
    // virtual void affect(const std::vector<PhysicsEntity*>& entities);
    
    virtual void update(float dt) override;
    
};

#endif /* PhysicsMedium_hpp */