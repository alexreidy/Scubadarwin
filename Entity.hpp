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

// Might want to just define ShapeEntity here in the base class.
// Shapes are pretty fundamental. Still maintain Vector2f position, and use it
// as the canonical position that shapes are positioned relative to. Not sure how we're
// going to handle relative shape positions. Consider the implications of side-scrolling.
// If we do this, we can then implement PhysicsEntity "early," utilizing getShapes()
// for volume calculations, etc.

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
