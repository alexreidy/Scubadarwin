//
//  util.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "util.hpp"

namespace sdu {

    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0, 1);

    float rin(float range)
    {
        return distribution(generator) * range;
    }

    float rsign(float x)
    {
        return rin(1) > 0.5 ? x : -x;
    }
    
    float magnitude(const Vector2f& vector)
    {
        return hypotf(vector.x, vector.y);
    }
    
    Vector2f norm(const Vector2f& vector)
    {
        const float hyp = magnitude(vector);
        return Vector2f(vector.x / hyp, vector.y / hyp);
    }
    
    Vector2f abs(const Vector2f& vector)
    {
        return Vector2f(std::abs(vector.x), std::abs(vector.y));
    }
    
};