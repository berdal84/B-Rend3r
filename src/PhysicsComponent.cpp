#include "PhysicsComponent.h"
#include <SDL2/SDL.h>

#include "Math.h" // for vec2
#include "Model.h"
#include <cstdlib>
#include <iostream>

using namespace brd;
using namespace std;

PhysicsComponent::PhysicsComponent(Model* _target)
{
	this->target = _target;
}

void PhysicsComponent::update(double _deltaTime)
{
	cout << "PhysicsComponent::update() - Begin" << endl;

	if ( target != nullptr )
	{
		cout << "PhysicsComponent::update() - Target found" << endl;
		

		// Update acceleration (attenuation)
		cout << "PhysicsComponent::update() - Update acceleration" << endl;
		float accelerationAttenuationFactor = 5.0f;
		acceleration = acceleration - acceleration * accelerationAttenuationFactor * _deltaTime;
		cout << "PhysicsComponent::update() - acceleration = " << acceleration.x << ", " << acceleration.y << ", " << acceleration.z << ")" << endl;
		
		// Update Speed
		cout << "PhysicsComponent::update() - Update speed" << endl;
		speed = speed + acceleration * _deltaTime - speed * accelerationAttenuationFactor * _deltaTime ;
		cout << "PhysicsComponent::update() - speed = " << speed.x << ", " << speed.y << ", " << speed.z << ")" << endl;

		// Update Position
		cout << "PhysicsComponent::update() - Update position" << endl;
		vec3 move = speed * _deltaTime;
		cout << "PhysicsComponent::update() - move = " << move.x << ", " << move.y << ", " << move.z << ")" << endl;

		this->target->translate(move);

		cout << "PhysicsComponent::update() - Done" << endl;
	}else{
		cout << "PhysicsComponent::update() - No target" << endl;
	}
}

void PhysicsComponent::addImpulse(vec3 _impulse){
	cout << "PhysicsComponent::addImpulse(" << _impulse.x << ", " << _impulse.y << ", " << _impulse.z << ")" << endl;
	acceleration = acceleration + _impulse;
}