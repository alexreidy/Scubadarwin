//
//  Entity.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 10/4/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "Entity.hpp"

Entity::~Entity() {}

Vector2f Entity::getPosition() const
{
    return position;
}

void Entity::setPosition(const Vector2f& position)
{
    this->position = position;
}

void Entity::move(const Vector2f& offset)
{
    Entity::setPosition(getPosition() + offset);
}