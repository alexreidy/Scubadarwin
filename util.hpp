//
//  util.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <set>

namespace sdu {

    using sf::Vector2f;
    
    // Returns a random float on [0, range]
    float rin(float range);
    
    // Returns x with a random sign (+/-)
    float rsign(float x);
    
    float magnitude(const Vector2f& vector);
    
    Vector2f norm(const Vector2f& vector);
    
    Vector2f abs(const Vector2f& vector);
    
};

#endif /* util_hpp */