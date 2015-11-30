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
#include "SimEntity.hpp"

using sf::CircleShape;
using sf::RectangleShape;
using sf::Color;

class ImpulseReceiver{};

class Organism;

class Organ : public SimEntity, ImpulseReceiver {
public:
    Organ(Organism* organism = nullptr);
    virtual ~Organ();
    
    virtual void update(float dt) override;
    
    virtual void affect(SimEntity* entity) override;
    
    virtual const Vector2f& getVelocity() const override;
    
    void setParentOrganism(Organism* organism);
    
protected:
    Organism* organism;
    
    void initializePosition();
    
};

#endif /* Organ_hpp */