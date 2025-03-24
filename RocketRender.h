#pragma once

#include "surface.h"
#include "IShip.h"
#include <cstdio>

namespace Tmpl8 {
	class IEntity;
	class RocketRender : public IShip
	{
	public:
		RocketRender(int direction = 0) : IShip(direction) { printf("Render: %d\n", this->direction); }
		void update(Surface* screen, IEntity* entity, IEntity* player);
	};
}
