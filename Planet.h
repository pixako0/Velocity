#pragma once

namespace Tmpl8 {
	class Planet
	{
	public:
		int x = 0;
		int y = 0;

		int gravityRange = 200;
		int planetsize = 65;

		int frame = 100;
		int frameCount = 0;
		int frameDelay = 4;
		int frameDelayCount = 0;

		void nextFrame();
	};
}

