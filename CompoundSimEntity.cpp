//
//  CompoundSimEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/18/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "CompoundSimEntity.hpp"

CompoundSimEntity::~CompoundSimEntity()
{
    for (auto entity : getPhysicsEntities()) {
        delete entity;
    }
}

float CompoundSimEntity::getMass() const
{
    if (mass >= 0) return mass;
    
    float m = 0;
    for (auto entity : getPhysicsEntities()) {
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
    for (auto c : getPhysicsEntities()) if (c->touching(entity)) return true;
    return false;
}

void CompoundSimEntity::setPosition(const Vector2f& position)
{
    Vector2f offset = position - getPosition();
    Entity::setPosition(position);
    for (auto entity : getPhysicsEntities()) {
        entity->move(offset);
    }
}

void CompoundSimEntity::move(const Vector2f& offset)
{
    Entity::move(offset);
    for (auto entity : getPhysicsEntities()) {
        entity->move(offset);
    }
}

const std::vector<Shape*>& CompoundSimEntity::getShapes() const
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

void CompoundSimEntity::addPhysicsEntity(PhysicsEntity* entity)
{
    constituents.push_back(entity);
    shapeCount += entity->getShapeCount();
    shapesCached = false;
}

void CompoundSimEntity::removePhysicsEntity(PhysicsEntity* entity)
{
    for (int i = 0; i < constituents.size(); i++) {
        if (constituents.at(i) == entity) {
            constituents.erase(constituents.begin() + i);
        }
    }
    shapeCount -= entity->getShapeCount();
    shapesCached = false;
}

const std::vector<PhysicsEntity*>& CompoundSimEntity::getPhysicsEntities() const
{
    return constituents;
}

int CompoundSimEntity::getShapeCount() const
{
    return shapeCount;
}

void CompoundSimEntity::addShape(Shape* shape) {}
