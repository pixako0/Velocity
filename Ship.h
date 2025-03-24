#pragma once
#include "surface.h"
#include "IShip.h"

namespace Tmpl8 {
	class Ship : public IShip
	{
	public:
		Ship() : IShip(0) {}
		void update(Surface* screen, IEntity* entity, IEntity* player);
	};
}

