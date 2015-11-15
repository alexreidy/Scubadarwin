//
//  ShapeEntity.hpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/20/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#ifndef ShapeEntity_hpp
#define ShapeEntity_hpp

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "util.hpp"

using sf::Shape;
using sf::Color;

class ShapeEntity : public Entity {
public:
    virtual ~ShapeEntity();
    
    // Positions of added shapes are offsets relative to getPosition().
    virtual void addShape(Shape* shape);
        
    // Not strictly encapsulated in favor of performance
    virtual const std::vector<Shape*>& getShapes() const;
    
    virtual int getShapeCount() const;
    
    virtual void setPosition(const Vector2f& position) override;
    
    virtual void move(const Vector2f& offset) override;
    
    virtual bool touching(const ShapeEntity* entity) const;
    
    void setColor(const Color& color);
    
    virtual ShapeEntity* clone() const = 0;
    
protected:
    mutable std::vector<Shape*> shapes;
    
};

#endif /* ShapeEntity_hpp */