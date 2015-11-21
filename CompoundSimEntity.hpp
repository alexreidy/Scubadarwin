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
    
    virtual const std::vector<Shape*>& getShapes() const override;
    
    const std::vector<SimEntity*>& getConstituentEntities() const;
    
    virtual int getShapeCount() const override;
    
    virtual void addShape(Shape* shape) override;
    
    virtual bool touching(const ShapeEntity* entity) const override;
    
    virtual void setPosition(const Vector2f& position) override;
    
    virtual void move(const Vector2f& offset) override;
    
    virtual float getDensity() const override;
    
    virtual void setDensity(float density) override;
    
    virtual float getMass() const override;
        
    void addEntity(SimEntity* entity);
    
    void removeEntity(SimEntity* entity);
    
protected:
    std::vector<SimEntity*> constituents;
    
private:
    
    bool shapesCached = false;
    
    mutable float mass = -1;
    
    int shapeCount = 0;
    
};

#endif /* CompoundSimEntity_hpp */
