//
//  WaterMedium.cpp
//  Scubadarwin
//
//  Created by Alex Reidy on 11/7/15.
//  Copyright © 2015 Alex Reidy. All rights reserved.
//

#include "WaterMedium.hpp"

WaterMedium::WaterMedium(std::vector<Shape*> shapes, float density)
{
    this->density = density;
    setShapes(shapes);
}

WaterMedium::~WaterMedium() {}

float WaterMedium::calcDrag(float velocity, float area) const
{
    auto drag = 0.5 * density * pow(velocity, 2) * area * 0.05;
    if (velocity > 0) return -drag;
    return drag;
}

void WaterMedium::affect(PhysicsEntity* entity)
{
    const auto velocity = entity->getVelocity();
    const auto volume = entity->getVolume();

    entity->applyForce(
        Vector2f(
            calcDrag(velocity.x, volume),
            calcDrag(velocity.y, volume)
        )
    );
    /*
    float displacedWaterMass = entity->getVolume() * density;
    
    auto displacedWaterForce = displacedWaterMass * entity->getGravityAcceleration();
    
    auto entityForce = entity->getMass() * entity->getGravityAcceleration();
    
    std::cout << "entitymass = " << entity->getMass() << " ... watermass = " << displacedWaterMass << std::endl;
    
    std::cout << "entity_density = " << entity->getDensity() << std::endl;
    

    entity->applyForce(entityForce - displacedWaterForce);*/
    
}