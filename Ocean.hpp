//
//  Ocean.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/8/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Ocean_hpp
#define Ocean_hpp

#include "PlanetaryFluidZone.hpp"

class Ocean : public PlanetaryFluidZone {
public:
    Ocean(std::vector<Shape*> shapes);
    
    virtual ~Ocean();
    
};

#endif /* Ocean_hpp */
