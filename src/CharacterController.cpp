#include "CharacterController.h"
#include <SDL2/SDL.h>

#include "Math.h" // for vec2
#include "Model.h"
#include <cstdlib>
#include <iostream>

using namespace brd;
using namespace std;
#include "PhysicsComponent.h"

CharacterController::CharacterController(PhysicsComponent* _target)
{
	this->target = _target;
}

void CharacterController::update(double _deltaTime)
{
	cout << "CharacterController::update() - Begin" << endl;

	if ( target != nullptr )
	{
		cout << "CharacterController::update() - Target found" << endl;
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		cout << "CharacterController::update() - Reading keyboard state" << endl;
		float left  = 0.0f;
		float up    = 0.0f;
		float right = 0.0f;
		float down  = 0.0f;

		if ( state[SDL_SCANCODE_LEFT] )  left  = 1.0f;
		if ( state[SDL_SCANCODE_UP] )    up    = 1.0f;
		if ( state[SDL_SCANCODE_RIGHT] ) right = 1.0f;
		if ( state[SDL_SCANCODE_DOWN] )  down  = 1.0f;

		cout << "CharacterController::update() - Setting direction to apply" << endl;
		vec3 direction;
		direction.x = right - left;
		direction.y = up - down;
		direction.z = 0.0f;
		
		this->target->addImpulse(direction.normalize() * 1000.0f);
		cout << "CharacterController::update() - Done" << endl;
	}else{
		cout << "CharacterController::update() - No target" << endl;
	}
}