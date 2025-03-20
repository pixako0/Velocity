#pragma once
#include "IEntity.h"

namespace Tmpl8 {
	class Enemy : public IEntity
	{
	public:
		int GetMaxVelocity() const override { return 50; }
		float acceleration = 0.3f;
	};
}
