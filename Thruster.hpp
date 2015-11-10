//
//  Thruster.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/9/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Thruster_hpp
#define Thruster_hpp

#include "Organism.hpp"
#include "Organ.hpp"

using sf::CircleShape;

class Thruster : public Organ {
public:
    Thruster(Organism* organism);
    
    virtual ~Thruster();
    
    virtual void update(float dt) override;
    
};

#endif /* Thruster_hpp */
