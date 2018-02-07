#pragma once

namespace brd{

	/*
		class Component : 

		each Model has zero or more Components.
		each Type of Component achieve different functions such as :

			- PhysicsComponent : simulate physics
			- Transform :        locate in space
			etc.
	*/
	enum ComponentType_ /* Type_[classname]*/
	{
		ComponentType_Physics,
		ComponentType_Transform,
		ComponentType_Shape,
		ComponentType_KeyboardController,
		ComponentType_COUNT
	};

	template <class T>
	class Component
	{
	public:

		Component(){};
		~Component(){};
		ComponentType_        getType()const{return T::type;};
	};
}