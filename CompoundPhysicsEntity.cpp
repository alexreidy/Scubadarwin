//
//  CompoundPhysicsEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/10/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "CompoundPhysicsEntity.hpp"

CompoundPhysicsEntity::~CompoundPhysicsEntity()
{
    for (auto entity : getPhysicsEntities()) {
        delete entity;
    }
}

float CompoundPhysicsEntity::getMass() const
{
    if (mass >= 0) return mass;
    
    float m = 0;
    for (auto entity : getPhysicsEntities()) {
        m += entity->getMass();
    }
    
    return mass = m;
}

float CompoundPhysicsEntity::getDensity() const
{
    return getMass() / getVolume();
}

void CompoundPhysicsEntity::setDensity(float density) {}

bool CompoundPhysicsEntity::touching(const ShapeEntity* entity) const
{
    for (auto c : getPhysicsEntities()) if (c->touching(entity)) return true;
    return false;
}

void CompoundPhysicsEntity::setPosition(const Vector2f& position)
{
    Vector2f offset = position - getPosition();
    Entity::setPosition(position);
    for (auto entity : getPhysicsEntities()) {
        entity->move(offset);
    }
}

void CompoundPhysicsEntity::move(const Vector2f& offset)
{
    Entity::move(offset);
    for (auto entity : getPhysicsEntities()) {
        entity->move(offset);
    }
}

const std::vector<Shape*>& CompoundPhysicsEntity::getShapes() const
{
    if (shapesCached) return shapes;
    
    shapes = std::vector<Shape*>(getShapeCount());
    
    int i = 0;
    for (auto entity : getPhysicsEntities()) {
        for (auto shape : entity->getShapes()) {
            shapes[i] = shape;
            i++;
        }
    }
    
    this->shapes = shapes;
    return shapes;
}

void CompoundPhysicsEntity::addPhysicsEntity(PhysicsEntity* entity)
{
    constituents.push_back(entity);
    shapeCount += entity->getShapeCount();
    shapesCached = false;
}

void CompoundPhysicsEntity::removePhysicsEntity(PhysicsEntity* entity)
{
    for (int i = 0; i < constituents.size(); i++) {
        if (constituents.at(i) == entity) {
            constituents.erase(constituents.begin() + i);
        }
    }
    shapeCount -= entity->getShapeCount();
    shapesCached = false;
}

const std::vector<PhysicsEntity*>& CompoundPhysicsEntity::getPhysicsEntities() const
{
    return constituents;
}

int CompoundPhysicsEntity::getShapeCount() const
{
    return shapeCount;
}

void CompoundPhysicsEntity::addShape(Shape* shape) {}
