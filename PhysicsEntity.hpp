//
//  PhysicsEntity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef PhysicsEntity_hpp
#define PhysicsEntity_hpp

#include "ShapeEntity.hpp"

class PhysicsEntity : public ShapeEntity {
public:
    virtual ~PhysicsEntity();
    
    virtual float getDensity() const;
    
    virtual void setDensity(float density);
    
    virtual float getMass() const;

    virtual float getVolume() const;
    
    void applyForce(const Vector2f& force);
    
    void setForce(const Vector2f& force);
    
    void setVelocity(const Vector2f& velocity);
    
    Vector2f getVelocity() const;
    
    virtual void updatePhysics(float dt);
    
    virtual void update(float dt) override;
    
    virtual void addShape(Shape* shape) override;
    
private:
    Vector2f velocity, force;
    
    float density = 1;
    
    // We cache getVolume(). Set volume to UNCERTAIN_VOLUME
    // when getVolume() should recompute.
    static const int UNCERTAIN_VOLUME = -1;
    
    mutable float volume = UNCERTAIN_VOLUME;
    
};

#endif /* PhysicsEntity_hpp */
