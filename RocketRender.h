#pragma once

#include "surface.h"
#include "IShip.h"

namespace Tmpl8 {
	class IEntity;
	class RocketRender : public IShip
	{
	public:
		void update(Surface* screen, IEntity* entity, IEntity* player);
	};
}
