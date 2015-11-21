//
//  Organism.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include "CompoundSimEntity.hpp"
#include "Organ.hpp"

class Organ;

class Organism : public CompoundSimEntity {
public:
    Organism();
    
    virtual ~Organism();
    
    static Organism* randomlyGenerateOrganism(int organCount = 1);
    
    bool isAlive() const;
    
    void die();
    
    void changeHp(float change);
    
    Organism* reproduce();
    
    //virtual ShapeEntity* clone() const override;
    
    void update(float dt) override;
    
    void changeNutrients(float delta);
    
    virtual ShapeEntity* makeNewInstance() const override;
    
    virtual ShapeEntity* clone() const override;
    
    virtual void affect(SimEntity* entity) override;
    
    virtual bool canBeDeleted() const override;
    
private:
    float hp = 100;
    
    float nutrients = 0;
    
};

#endif /* Organism_hpp */
