//
//  Chloroplast.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/15/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Chloroplast_hpp
#define Chloroplast_hpp

#include "Organ.hpp"

using sf::Color;

class Chloroplast : public Organ {
public:
    Chloroplast(Organism* organism = nullptr, bool randomlyGenerated = false);
    
    virtual ~Chloroplast();
    
    virtual void update(float dt) override;
        
    virtual ShapeEntity* makeNewInstance() const override;
    
    virtual void affect(SimEntity* entity) override;
    
};

#endif /* Chloroplast_hpp */
