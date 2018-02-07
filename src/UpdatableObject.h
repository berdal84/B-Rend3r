#pragma once
namespace brd{

	/*
		class UpdatableObject

		This class is an interface for objects that :

		  - needs to be updated each frame
		  
	*/

	class UpdatableObject
	{
	public:
		UpdatableObject(){};
		~UpdatableObject(){};
		virtual void update(double _deltaTime)=0;
	};
}