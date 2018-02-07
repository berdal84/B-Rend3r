#pragma once
#include "Physics.h"
#include "Math.h"
#include "UpdatableObject.h"
#include "Component.h"

namespace brd{
	/* Forward declarations */
	class Model;

	class Physics: public Component<Physics>, public UpdatableObject
	{
	public:
		Physics(Model* _target);
		~Physics(){};
		void update           (double)override;
		void addImpulse       (vec3 _impulse);
		static ComponentType_ s_type;

	private:
		Model* target       = nullptr;
		vec3   acceleration = vec3(0.0f);
		vec3   speed        = vec3(0.0f);
		float  speedMax     = 1000.0f;
	};
}