//
//  Environment.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/20/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include "CompoundSimEntity.hpp"

// Intended for use as a Zone container.
// Zones are direct descendents of SimEntity, which
// doesn't support constituents, which are essential to our
// "touch->affect" architecture. We don't want to
// have a special loop for Zones, though, so we instead
// make them constituents of a CompoundSimEntity container
// such that they affect other SimEntity constituents.

class Environment : public CompoundSimEntity {
public:
    virtual ~Environment();
    
    virtual void update(float dt) override;
    
    virtual void affect(SimEntity* entity) override;
    
    virtual ShapeEntity* makeNewInstance() const override;
};

#endif /* Environment_hpp */
