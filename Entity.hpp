//
//  Entity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#include "util.hpp"

using sf::Vector2f;

class Entity {
public:
    virtual ~Entity();
    
    virtual Vector2f getPosition() const;
    
    virtual void setPosition(const Vector2f& position);
    
    virtual void move(const Vector2f& offset);
    
    virtual void update(float dt) = 0;
    
private:
    Vector2f position;
    
};

#endif /* Entity_hpp */
