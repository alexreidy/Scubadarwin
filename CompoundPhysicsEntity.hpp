//
//  CompoundPhysicsEntity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/10/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef CompoundPhysicsEntity_hpp
#define CompoundPhysicsEntity_hpp

#include "PhysicsEntity.hpp"

class CompoundPhysicsEntity : public PhysicsEntity {
public:
    virtual ~CompoundPhysicsEntity();
        
    virtual float getDensity() const override;
    
    virtual void setDensity(float density) override;
    
    virtual float getMass() const override;
    
    virtual bool touching(const ShapeEntity& entity) const override;
    
    virtual void setPosition(const Vector2f& position) override;
    
    virtual void move(const Vector2f& offset) override;
    
    void addPhysicsEntity(PhysicsEntity* entity);
    
    void removePhysicsEntity(PhysicsEntity* entity);
    
    virtual std::vector<Shape*> getShapes() const override; // should we really return a copy of this vec?
    
    virtual int getShapeCount() const override;
    
    virtual void addShape(Shape* shape) override;
    
private:
    std::vector<PhysicsEntity*> constituents;
    
    int shapeCount = 0;
    
};

#endif /* CompoundPhysicsEntity_hpp */