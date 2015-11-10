//
//  WaterMedium.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/7/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef WaterMedium_hpp
#define WaterMedium_hpp

#include "PhysicsMedium.hpp"

class WaterMedium : public PhysicsMedium {
public:
    WaterMedium(std::vector<Shape*> shapes, float density);
    
    virtual ~WaterMedium();
    
    virtual void affect(PhysicsEntity* entity) override;

    float calcDrag(float velocity, float area) const;
    
protected:
    float density;
    
};

#endif /* WaterMedium_hpp */
