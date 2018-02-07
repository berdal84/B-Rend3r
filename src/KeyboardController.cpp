#include "KeyboardController.h"
#include <SDL2/SDL.h>

#include "Math.h" // for vec2
#include "Model.h"
#include <cstdlib>
#include <iostream>
#include "Physics.h"

using namespace brd;
using namespace std;

ComponentType_ KeyboardController::s_type = ComponentType_KeyboardController;

KeyboardController::KeyboardController(Model* _target)
{
	this->target = _target;
}

void KeyboardController::update(double _deltaTime)
{
	cout << "KeyboardController::update() - Begin" << endl;

	if ( target != nullptr && target->hasComponent<Physics>())
	{
		cout << "KeyboardController::update() - Target found" << endl;
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		cout << "KeyboardController::update() - Reading keyboard state" << endl;
		float left  = 0.0f;
		float up    = 0.0f;
		float right = 0.0f;
		float down  = 0.0f;

		if ( state[SDL_SCANCODE_LEFT] )  left  = 1.0f;
		if ( state[SDL_SCANCODE_UP] )    up    = 1.0f;
		if ( state[SDL_SCANCODE_RIGHT] ) right = 1.0f;
		if ( state[SDL_SCANCODE_DOWN] )  down  = 1.0f;

		cout << "KeyboardController::update() - Setting direction to apply" << endl;
		vec3 direction;
		direction.x = right - left;
		direction.y = up - down;
		direction.z = 0.0f;
		
		target->getComponent<Physics>()->addImpulse(direction.normalize() * 1000.0f);
		cout << "KeyboardController::update() - Done" << endl;
	}else{
		cout << "KeyboardController::update() - No target" << endl;
	}
}