//
//  GravityZone.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef GravityZone_hpp
#define GravityZone_hpp

#include "Zone.hpp"

class GravityZone : public Zone {
public:
    virtual ~GravityZone();
    
    virtual void affect(SimEntity* entity) override;
    
    void setGravityAcceleration(const Vector2f& g);
    
    Vector2f getGravityAcceleration() const;
    
private:
    Vector2f g;
    
};

#endif /* GravityZone_hpp */