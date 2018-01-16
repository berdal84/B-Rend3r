#pragma once
#include "PhysicsComponent.h"
#include "Math.h"
#include "UpdatableObject.h"

namespace brd{
	/* Forward declarations */
	class Model;

	class PhysicsComponent: public UpdatableObject
	{
	public:
		PhysicsComponent(Model* _target);
		~PhysicsComponent(){};
		void update           (double)override;
		void addImpulse       (vec3 _impulse);
	private:
		Model* target       = nullptr;
		vec3   acceleration = vec3(0.0f);
		vec3   speed        = vec3(0.0f);
		float  speedMax     = 1000.0f;
	};
}