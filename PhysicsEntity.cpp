//
//  PhysicsEntity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "PhysicsEntity.hpp"

PhysicsEntity::~PhysicsEntity() {}

float PhysicsEntity::getDensity() const
{
    return density;
}

void PhysicsEntity::setDensity(float density)
{
    this->density = density;
}

float PhysicsEntity::getVolume() const
{
    if (volume == UNCERTAIN_VOLUME) {
        volume = 0;
        for (auto shape : getShapes()) {
            const auto rect = shape->getGlobalBounds();
            volume += rect.width * rect.height;
        }
    }
    return volume;
}

float PhysicsEntity::getMass() const
{
    return getDensity() * getVolume();
}

void PhysicsEntity::applyForce(const Vector2f& force)
{
    this->force += force;
}

void PhysicsEntity::setForce(const Vector2f &force)
{
    this->force = force;
}

void PhysicsEntity::setVelocity(const Vector2f& velocity)
{
    this->velocity = velocity;
}

Vector2f PhysicsEntity::getVelocity() const
{
    return velocity;
}

void PhysicsEntity::updatePhysics(float dt)
{
    auto accel = Vector2f(force.x / getMass(), force.y / getMass());
    velocity += accel * dt;
    move(velocity * dt);
    setForce(Vector2f());
}

void PhysicsEntity::update(float dt)
{
    updatePhysics(dt);
}

void PhysicsEntity::addShape(sf::Shape *shape)
{
    ShapeEntity::addShape(shape);
    volume = UNCERTAIN_VOLUME;
}