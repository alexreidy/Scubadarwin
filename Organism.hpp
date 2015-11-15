//
//  Organism.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include "CompoundPhysicsEntity.hpp"
#include "Organ.hpp"

class Organ;

class Organism : public CompoundPhysicsEntity {
public:
    Organism();
    
    virtual ~Organism();
    
    static Organism* randomlyGenerateOrganism(int organCount = 1);
    
    bool isAlive() const;
    
    void die();
    
    Organism* reproduce();
    
    void update(float dt) override;
    
    void changeNutrients(float delta);
    
    virtual ShapeEntity* clone() const override;
    
private:
    float hp = 0;
    
    float nutrients = 0;
    
};

#endif /* Organism_hpp */
