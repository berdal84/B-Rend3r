#pragma once
#include "UpdatableObject.h"

namespace brd{
	/* Forward declarations */
	class Model;
	class PhysicsComponent;
	
	class CharacterController: public UpdatableObject
	{
	public:
		CharacterController(PhysicsComponent* _target);
		~CharacterController(){};
		void update(double)override;
	private:
		PhysicsComponent* target       = nullptr;

		float  acceleration = 1000.0f;
		float  speed        = 0.0f;
		float  speedMax     = 1000.0f;
	};
}