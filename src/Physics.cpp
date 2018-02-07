#include "Physics.h"
#include <SDL2/SDL.h>

#include "Math.h" // for vec2
#include "Model.h"
#include <cstdlib>
#include <iostream>
#include "Component.h"
#include "Transform.h"

using namespace brd;
using namespace std;

ComponentType_ Physics::s_type = ComponentType_Physics;

Physics::Physics(Model* _target)
{
	this->target = _target;
}

void Physics::update(double _deltaTime)
{
	cout << "Physics::update() - Begin" << endl;

	if ( target != nullptr  && target->hasComponent<Transform>())
	{
		cout << "Physics::update() - Target found" << endl;
		

		// Update acceleration (attenuation)
		cout << "Physics::update() - Update acceleration" << endl;
		float accelerationAttenuationFactor = 5.0f;
		acceleration = acceleration - acceleration * accelerationAttenuationFactor * _deltaTime;
		cout << "Physics::update() - acceleration = " << acceleration.x << ", " << acceleration.y << ", " << acceleration.z << ")" << endl;
		
		// Update Speed
		cout << "Physics::update() - Update speed" << endl;
		speed = speed + acceleration * _deltaTime - speed * accelerationAttenuationFactor * _deltaTime ;
		cout << "Physics::update() - speed = " << speed.x << ", " << speed.y << ", " << speed.z << ")" << endl;

		// Update Position
		cout << "Physics::update() - Update position" << endl;
		vec3 move = speed * _deltaTime;
		cout << "Physics::update() - move = " << move.x << ", " << move.y << ", " << move.z << ")" << endl;

		target->getComponent<Transform>()->translate(move);

		cout << "Physics::update() - Done" << endl;
	}else{
		cout << "Physics::update() - No target" << endl;
	}
}

void Physics::addImpulse(vec3 _impulse){
	cout << "Physics::addImpulse(" << _impulse.x << ", " << _impulse.y << ", " << _impulse.z << ")" << endl;
	acceleration = acceleration + _impulse;
}