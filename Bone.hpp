//
//  Bone.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Bone_hpp
#define Bone_hpp

#include "Organism.hpp"
#include "Organ.hpp"

//class Organism;
//class Organ;

class Bone : public Organ {
public:
    Bone(Organism* organism);
    
    virtual ~Bone();
    
    virtual void update(float dt) override;
};

#endif /* Bone_hpp */