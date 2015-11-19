//
//  CompoundSimEntity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/18/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef CompoundSimEntity_hpp
#define CompoundSimEntity_hpp

#include "SimEntity.hpp"

class CompoundSimEntity : public SimEntity {
public:
    virtual ~CompoundSimEntity();
    
    virtual float getDensity() const override;
    
    virtual void setDensity(float density) override;
    
    virtual float getMass() const override;
    
    virtual bool touching(const ShapeEntity* entity) const override;
    
    virtual void setPosition(const Vector2f& position) override;
    
    virtual void move(const Vector2f& offset) override;
    
    void addPhysicsEntity(PhysicsEntity* entity);
    
    void removePhysicsEntity(PhysicsEntity* entity);
    
    const std::vector<PhysicsEntity*>& getPhysicsEntities() const;
    
    virtual const std::vector<Shape*>& getShapes() const override;
    
    virtual int getShapeCount() const override;
    
    virtual void addShape(Shape* shape) override;
    
private:
    std::vector<PhysicsEntity*> constituents;
    
    bool shapesCached = false;
    
    mutable float mass = -1;
    
    int shapeCount = 0;
    
};

#endif /* CompoundSimEntity_hpp */
