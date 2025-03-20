#pragma once
#include "IEntity.h"

namespace Tmpl8 {
	class Enemy : public IEntity
	{
	public:
		int maxVelocity = 20;
		float acceleration = 0.3f;
	};
}
