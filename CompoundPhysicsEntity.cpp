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
    for (auto entity : constituents) {
        delete entity;
    }
}

float CompoundPhysicsEntity::getMass() const // todo: cache this!!!!!
{
    float m = 0;
    for (auto entity : constituents) {
        m += entity->getMass();
    }
    return m;
}

float CompoundPhysicsEntity::getDensity() const
{
    return getMass() / getVolume();
}

void CompoundPhysicsEntity::setDensity(float density) {}

bool CompoundPhysicsEntity::touching(const ShapeEntity& entity) const
{
    for (auto c : constituents) if (c->touching(entity)) return true;
    return false;
}

void CompoundPhysicsEntity::setPosition(const Vector2f &position)
{
    Vector2f offset = position - getPosition();
    Entity::setPosition(position);
    for (auto entity : constituents) {
        entity->move(offset);
    }
}

void CompoundPhysicsEntity::move(const Vector2f& offset)
{
    Entity::move(offset);
    for (auto entity : constituents) {
        entity->move(offset);
    }
}

std::vector<Shape*> CompoundPhysicsEntity::getShapes() const
{
    std::vector<Shape*> shapes(getShapeCount());
    // todo: consider adapting the current shapes instance var.
    // This method is called EVERY update--far more frequently than
    // the occasional expensive shape removal.
    // There's definitely something more efficient out there: maybe a set?
    
    int i = 0;
    for (auto entity : constituents) {
        for (auto shape : entity->getShapes()) {
            shapes[i] = shape;
            i++;
        }
    }
    return shapes;
}

void CompoundPhysicsEntity::addPhysicsEntity(PhysicsEntity* entity)
{
    constituents.push_back(entity);
    shapeCount += entity->getShapeCount();
}

void CompoundPhysicsEntity::removePhysicsEntity(PhysicsEntity* entity)
{
    for (int i = 0; i < constituents.size(); i++) {
        if (constituents.at(i) == entity) {
            constituents.erase(constituents.begin() + i);
        }
    }
    shapeCount -= entity->getShapeCount();
}

int CompoundPhysicsEntity::getShapeCount() const
{
    return shapeCount;
}

void CompoundPhysicsEntity::addShape(Shape* shape) {}
