#pragma once

#include "surface.h"
#include <cstdio>

namespace Tmpl8 {
	class IEntity;
	class IShip
	{
	public:
		IShip(int direction = 0) {
			this->direction = direction;
			printf("Ship: %d\n", this->direction);
		}
		void update(Surface* screen, IEntity* entity, IEntity* player);
		int direction = 0;

		// idle animation
		int idleFrameCount = 0;
		int idleFrame = 3;
		int idleFrameDelay = 5;
		int idleFrameDelayCount = 0;

		// powerred animation
		int poweredFrameCount = 0;
		int poweredFrame = 4;
		int poweredFrameDelay = 5;
		int poweredFrameDelayCount = 0;

		// direction animation
		int directionTimeout = 10;
		int directionTimeoutCount = 0;
	private:
	};
}
