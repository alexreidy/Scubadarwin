//
//  Mouth.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 12/7/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Mouth_hpp
#define Mouth_hpp

#include "Organ.hpp"

class Mouth : public Organ {
public:
    Mouth(Organism* organism = nullptr, bool randomlyGenerated = false);
    
    virtual ~Mouth();
    
    virtual void update(float dt) override;
    
    virtual ShapeEntity* makeNewInstance() const override;
    
    virtual void affect(SimEntity* entity) override;
    
};

#endif /* Mouth_hpp */
