#pragma once
#include "UpdatableObject.h"
#include "Component.h"

namespace brd{
	/* Forward declarations */
	class Model;
	
	class KeyboardController: public UpdatableObject, public Component<KeyboardController>
	{
	public:
		KeyboardController(Model* _target);
		~KeyboardController(){};
		void update(double)override;
		static ComponentType_ s_type;
	private:
		Model* target       = nullptr;

		float  acceleration = 1000.0f;
		float  speed        = 0.0f;
		float  speedMax     = 1000.0f;
	};
}