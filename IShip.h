#pragma once

#include "surface.h"

namespace Tmpl8 {
	class IEntity;
	class IShip
	{
	public:
		void update(Surface* screen, IEntity* entity);
		int direction = 0;

	private:
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
	};
}
