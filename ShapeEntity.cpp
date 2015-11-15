//
//  ShapeEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/20/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "ShapeEntity.hpp"

ShapeEntity::~ShapeEntity()
{
    for (auto shape : getShapes()) {
        delete shape;
    }
}

const std::vector<Shape*>& ShapeEntity::getShapes() const
{
    return shapes;
}

void ShapeEntity::addShape(Shape* shape)
{
    shape->move(getPosition());
    shapes.push_back(shape);
}

int ShapeEntity::getShapeCount() const
{
    return shapes.size();
}

bool ShapeEntity::touching(const ShapeEntity* entity) const
{
    for (auto shape : getShapes()) {
        for (auto other : entity->getShapes()) {
            if (shape->getGlobalBounds().intersects(other->getGlobalBounds())) {
                return true;
            }
        }
    }
    return false;
}

void ShapeEntity::setPosition(const Vector2f& position)
{
    Vector2f offset = position - getPosition();
    Entity::setPosition(position);
    for (auto shape : getShapes()) {
        shape->move(offset);
    }
}

void ShapeEntity::move(const Vector2f& offset)
{
    Entity::move(offset);
    for (auto shape : getShapes()) {
        shape->move(offset);
    }
}

void ShapeEntity::setColor(const Color &color)
{
    for (auto shape : getShapes()) {
        shape->setFillColor(color);
    }
}