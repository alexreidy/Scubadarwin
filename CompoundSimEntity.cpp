//
//  CompoundSimEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/18/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "CompoundSimEntity.hpp"

CompoundSimEntity::CompoundSimEntity()
{

}

CompoundSimEntity::~CompoundSimEntity()
{
    for (auto entity : getConstituentEntities())
        delete entity;
    // ShapeEntity destructor calls virtual getShapes(), and
    // the shapes are already deleted in this destructor, so
    shapes.clear();
}

const std::list<SimEntity*>& CompoundSimEntity::getConstituentEntities() const
{
    return constituents;
}

void CompoundSimEntity::affect(const std::list<SimEntity*>& entities)
{
    for (auto constituent : getConstituentEntities()) {
        constituent->affect(entities);
    }
}

float CompoundSimEntity::getMass() const
{
    if (mass >= 0) return mass;
    
    float m = 0;
    for (auto entity : getConstituentEntities()) {
        m += entity->getMass();
    }
    
    return mass = m;
}

float CompoundSimEntity::getDensity() const
{
    return getMass() / getVolume();
}

void CompoundSimEntity::setDensity(float density) {}

bool CompoundSimEntity::touching(const ShapeEntity* entity) const
{
    for (auto c : getConstituentEntities()) if (c->touching(entity)) return true;
    return false;
}

void CompoundSimEntity::setPosition(const Vector2f& position)
{
    Vector2f offset = position - getPosition();
    Entity::setPosition(position);
    for (auto entity : getConstituentEntities()) {
        entity->move(offset);
    }
}

void CompoundSimEntity::move(const Vector2f& offset)
{
    Entity::move(offset);
    for (auto entity : getConstituentEntities()) {
        entity->move(offset);
    }
}

const std::vector<Shape*>& CompoundSimEntity::getShapes() const
{
    if (shapesCached) return shapes;
    
    shapes = std::vector<Shape*>(getShapeCount());
    
    int i = 0;
    for (auto entity : getConstituentEntities()) {
        for (auto shape : entity->getShapes()) {
            shapes[i] = shape;
            i++;
        }
    }
    
    this->shapes = shapes;
    
    return shapes;
}

void CompoundSimEntity::addEntity(SimEntity* entity)
{
    constituents.push_back(entity);
    shapeCount += entity->getShapeCount();
    shapesCached = false;
}

void CompoundSimEntity::removeEntity(SimEntity* entity)
{
    constituents.remove(entity);
    shapeCount -= entity->getShapeCount();
    delete entity;
    shapesCached = false;
}

int CompoundSimEntity::getShapeCount() const
{
    return shapeCount;
}

void CompoundSimEntity::addShape(Shape* shape) {}
