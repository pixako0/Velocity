#pragma once
#include "surface.h"

namespace Tmpl8 {
	class Player;
	class Ship
	{
	public:
		void update(Surface* screen, Player* player);
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
	};
}

