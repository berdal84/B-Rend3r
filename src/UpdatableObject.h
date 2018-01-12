#pragma once
namespace brd{
	class UpdatableObject
	{
	public:
		UpdatableObject(){};
		~UpdatableObject(){};
		virtual void update(double _deltaTime)=0;
	};
}