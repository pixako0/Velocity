#pragma once

#include "surface.h"
#include "IShip.h"
#include <cstdio>

namespace Tmpl8 {
	class IEntity;
	class RocketRender : public IShip
	{
	public:
		RocketRender(int direction = 0) : IShip(direction) { }
		void update(Surface* screen, IEntity* entity, IEntity* player);

	private:
		int rocketFrameCount = 0;
		int rocketFrame = 3;
		int rocketFrameDelay = 5;
		int rocketFrameDelayCount = 0;
	};
}
