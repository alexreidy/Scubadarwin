//
//  Photon.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 12/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Photon_hpp
#define Photon_hpp

#include "SimEntity.hpp"

using sf::CircleShape;

class Photon : public SimEntity {
public:
    Photon();
    
    virtual ~Photon();
    
    virtual void update(float dt) override;
    
    virtual void affect(SimEntity* entity) override;
    
    virtual ShapeEntity* makeNewInstance() const override;
    
    virtual bool canBeDeleted() const override;
    
};

#endif /* Photon_hpp */
