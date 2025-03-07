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
		int idleFrameDelay = 10;
		int idleFrameDelayCount = 0;
	};
}

