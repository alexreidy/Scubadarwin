//
//  Zone.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Zone_hpp
#define Zone_hpp

#include "SimEntity.hpp"

class Zone : public SimEntity {
public:
    virtual ~Zone();
            
    virtual void update(float dt) override;
    
};

#endif /* Zone_hpp */